#include "../headers/ChunkManager.h"
#include <thread.h>

ChunkManager::ChunkManager(Player* player, Time* time)
{
    this->player = player;
    this->time = time;

    framerate = 10;
    passedFrames = 0;

    chunkLoadsPerFrame  = 8;
    chunkLoadsThisFrame = 0;
    chunkUpdatesPerFrame  = 2;
    chunkUpdatesThisFrame = 0;
}

void logVector(glm::ivec3 v)
{
    std::cout << "x=" << v.x << " y=" << v.y << " z=" << v.z << std::endl;
}

void log(string msg)
{
    std::cout << msg << std::endl;
}

void log(int msg)
{
    std::cout << msg << std::endl;
}

void log(float msg)
{
    std::cout << msg << std::endl;
}

void ChunkManager::createChunkNeighbours(std::shared_ptr<Chunk> chunk)
{
    glm::ivec3 neighbourIndex;
    for (int n = 0; n < 6; n++)
    {
        neighbourIndex = glm::ivec3(chunk->chunkIndex.x + CubeCreator::defaultNormals[n].x, // normals equal neighbour directions
                                    chunk->chunkIndex.y + CubeCreator::defaultNormals[n].y,
                                    chunk->chunkIndex.z + CubeCreator::defaultNormals[n].z);

        if (createdChunks.find(neighbourIndex) == createdChunks.end()) // neighbour doesn't exist
        {
            // create neighbour
            std::shared_ptr<Chunk> neighbour(new Chunk);
            neighbour->setChunkIndex(neighbourIndex);

            chunks[neighbourIndex] = neighbour;
            createdChunks.insert(neighbourIndex);

            neighbour->neighbours[((n&1) == 0) ? n+1 : n-1] = chunk;
            chunk->neighbours[n] = neighbour;
        }
        else
        {
            // neighbour exists
            if (chunk->neighbours[n] == nullptr)
            {
                chunk->neighbours[n] = chunks[neighbourIndex]; // link neighbour
                chunk->neighbours[n]->neighbours[((n&1) == 0) ? n+1 : n-1] = chunk; // backlink chunk

                 // update info about neighbours
                if (chunk->neighbours[n]->rendered)
                {
                    chunk->generatedNeighbourCount++;
                    chunk->renderedNeighbourCount++;
                }
                else if (chunk->neighbours[n]->generated)
                    chunk->generatedNeighbourCount++;
            }
        }
    }
}

void ChunkManager::generateChunkThread(std::shared_ptr<Chunk> chunk)
{
    chunk->generate();
    for (int n = 0; n < 6; n++)
    {
        if (chunk->neighbours[n] != nullptr)
            chunk->neighbours[n]->generatedNeighbourCount++;
        else
            return;
    }
    generatedChunks.insert(chunk->chunkIndex);
    if (!Settings::useThreading)
        chunk->update();

    chunk->busy = false;
}

void ChunkManager::generateChunk(std::shared_ptr<Chunk> chunk)
{
    if (!chunk->busy)
    {
        chunk->busy = true;
        if (Settings::useThreading)
            std::thread (&ChunkManager::generateChunkThread, this, chunk).detach();
        else
            generateChunkThread(chunk);
    }
}

void ChunkManager::prepareChunkToRender(std::shared_ptr<Chunk> chunk)
{
    if (!chunk->busy)
    {

        if (!chunk->generated)
            createChunkNeighbours(chunk);

        for (int n = 0; n < 6; n++)
        {
            if (chunk->neighbours[n] != nullptr)
            {
                if (!chunk->neighbours[n]->generated && !chunk->neighbours[n]->busy)
                {
                    createChunkNeighbours(chunk->neighbours[n]);
                    generateChunk(chunk->neighbours[n]);
                }
            }
        }

        if (!chunk->generated)
            generateChunk(chunk);

        if (!Settings::useThreading)
        {
            chunk->rendered = true;
            renderedChunks.push_back(chunk);
        }

        chunk->preparedToRender = true;
    }
}

void ChunkManager::degenerateChunk(std::shared_ptr<Chunk> chunk)
{
    chunk->busy = true;

    generatedChunks.erase(chunk->chunkIndex);
    chunk->generated = false;

    for (int n = 0; n < 6; n++)
    {
        if (chunk->neighbours[n] != nullptr)
        {
            if (!chunk->neighbours[n]->inRenderDistance)
                deleteChunk(chunk->neighbours[n]);
            //chunk->neighbours[n]->generatedNeighbourCount--;
        }
    }
    chunk->busy = false;
}

void ChunkManager::derenderChunk(std::shared_ptr<Chunk> chunk)
{
    chunk->busy = true;

    renderedChunks.remove(chunk);
    chunk->rendered = false;
    chunk->resetMesh();

    std::shared_ptr<Chunk> neighbour;

    for (int n = 0; n < 6; n++)
    {
        if (chunk->neighbours[n] != nullptr)
        {
            if (!chunk->neighbours[n]->inRenderDistance)
                degenerateChunk(chunk->neighbours[n]);
            //chunk->neighbours[n]->renderedNeighbourCount--;
        }
    }
    chunk->busy = false;
}

void ChunkManager::deleteChunk(std::shared_ptr<Chunk> chunk)
{
    chunk->busy = true;
    createdChunks.erase(chunk->chunkIndex);
    chunks.erase(chunk->chunkIndex);
    for (int n = 0; n < 6; n++)
    {
        if (chunk->neighbours[n] != nullptr)
        {
            chunk->neighbours[n]->neighbours[((n&1) == 0) ? n+1 : n-1] = nullptr; // unlink chunk from neighbour
        }
    }
    /*log("unload");
    std::cout << chunk.use_count() << std::endl;*/
}

glm::ivec3 ChunkManager::getPlayerChunkIndex()
{
    return glm::ivec3((int)player->controller->camera->position.x >> Settings::log_chunkSize,
                      (int)player->controller->camera->position.y >> Settings::log_chunkSize,
                      (int)player->controller->camera->position.z >> Settings::log_chunkSize);
}

void ChunkManager::loadChunksAroundPlayer()
{
    if (passedFrames >= framerate)
    {
        passedFrames = 0;
        //playerChunkIndex = getPlayerChunkIndex();
        int n;
        float distance;
        std::shared_ptr<Chunk> neighbour;
        chunkLoadsThisFrame = 0;
        chunkUpdatesThisFrame = 0;
        for (std::shared_ptr<Chunk> chunk : renderedChunks) // all rendered chunks
        {
            if(chunk->renderedNeighbourCount != 6) // chunk is missing neighbours
            {
                for (n = 0; n < 6; n++) // loop through all neighbours
                {

                    neighbour = chunk->neighbours[n];
                    if (neighbour != nullptr) // neighbour in renderDistance
                    {
                        distance = Math::vectorDistance(neighbour->chunkIndex, playerChunkIndex);
                        if (distance < Settings::renderDistance)
                        {
                            neighbour->inRenderDistance = true;
                            if (!neighbour->rendered)
                            {
                                if (neighbour->preparedToRender)
                                {
                                    if (chunkUpdatesThisFrame < chunkUpdatesPerFrame) {
                                        neighbour->update();
                                        neighbour->preparedToRender = false;
                                        neighbour->rendered = true;
                                        renderedChunks.push_back(neighbour);
                                        chunkUpdatesThisFrame++;
                                    }
                                }
                                else
                                {
                                    if (chunkLoadsThisFrame < chunkLoadsPerFrame) {
                                        prepareChunkToRender(neighbour);
                                        chunkLoadsThisFrame++;
                                    }
                                }
                            }
                        }
                        else
                        {  // neighbour out of renderDistance
                            neighbour->inRenderDistance = false;

                            /*if (neighbour->rendered)
                            {
                                derenderChunk(neighbour);
                            }
                            else if (neighbour->generated)
                            {
                                degenerateChunk(neighbour);
                            }*/
                            /*else if (neighbour->generatedNeighbourCount == 0 && !neighbour->busy)
                            {
                                deleteChunk(neighbour);
                            }*/

                        }
                    }
                }
                /*if (!chunk->inRenderDistance && chunk->generatedNeighbourCount == 0) {
                    unloadChunk(neighbour);
                    deleteChunk(chunk);
                }*/
            }
        }
    }
    passedFrames++;
}

void ChunkManager::init()
{
    playerChunkIndex = getPlayerChunkIndex();
    player->controller->camera->pitch = -90.0f;
    player->controller->camera->position.y = 500.0f;

    std::shared_ptr<Chunk> chunk(new Chunk);
    chunks[playerChunkIndex] = chunk;
    chunk->setChunkIndex(playerChunkIndex);
    createdChunks.insert(playerChunkIndex);
    prepareChunkToRender(chunk);

    //player->controller->camera->position.y = 400;

    Settings::useThreading = true;
}

void ChunkManager::update()
{
    loadChunksAroundPlayer();
}

void ChunkManager::render()
{
    for (std::list<std::shared_ptr<Chunk>>::iterator chunk = renderedChunks.begin(); chunk != renderedChunks.end(); ++chunk)
    {
        (*chunk)->render();
    }
}
