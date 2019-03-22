#include "../headers/Chunk.h"

Chunk::Chunk()
{
    generatedNeighbourCount = 0;
    renderedNeighbourCount  = 0;
    inRenderDistance = true;
}

void Chunk::setChunkIndex(glm::ivec3 chunkIndex)
{
    glm::vec3 chunkPosition(chunkIndex.x << Settings::log_chunkSize,
                            chunkIndex.y << Settings::log_chunkSize,
                            chunkIndex.z << Settings::log_chunkSize);

    cubeCreator.setOffset(chunkPosition);

    this->chunkIndex = chunkIndex;
    this->chunkPosition = chunkPosition;
    //Debug::outlineChunk(chunkPosition);
}

/*void Chunk::initData()
{
    data = new int**[Settings::chunkSize];
    int x, y;
    for (x = 0; x < Settings::chunkSize; x++)
    {
        data[x] = new int*[Settings::chunkSize];
        for (y = 0; y < Settings::chunkSize; y++)
        {
            data[x][y] = new int[Settings::chunkSize];
        }
    }
}

void Chunk::deleteData()
{
    int x, y;
    for (x = 0; x < Settings::chunkSize; x++)
    {
        for (y = 0; y < Settings::chunkSize; y++)
        {
            delete [] data[x][y];
        }
        delete [] data[x];
    }
    delete [] data;
}*/

void Chunk::generate()
{
    //initData();
    int seaLevel = 64;
    int cx, cy, cz, x, y, z, baseNoise, base;//, stoneNoise, dirtNoise, stone, dirt, grass;
    for (cx = 0; cx < Settings::chunkSize; cx++)
    {
        x = cx + chunkPosition.x;
        for (cz = 0; cz < Settings::chunkSize; cz++)
        {
            z = cz + chunkPosition.z;
            baseNoise = Noise::getOctave2(x, z, 4, 128.0f, 0.8f, 16.0f, 0.9f) + 80.0f;
            /*stoneNoise = baseNoise + Noise::get2(x, z, 64.0f, 16.0f, 1.0f) + 32.0f;
            dirtNoise = baseNoise + Noise::get2(x, z, 128.0f, 16.0f, 1.0f) + 64.0f;*/
            for (cy = 0; cy < Settings::chunkSize; cy++)
            {
                y = cy + chunkPosition.y;
                base = baseNoise + Noise::get3(x, y, z, 32.0f, 8.0f);
                /*stone = stoneNoise + Noise::get3(x, y, z, 64.0f, 8.0f, 1.0f) + 16.0f;
                dirt = dirtNoise + Noise::get3(x, y, z, 128.0f, 32.0f, 1.0f) + 32.0f;
                grass = dirt + 1;*/

                if (y >= 0)
                {
                    if (y < base)
                        data[cx][cy][cz] = 5;
                    /*else if (y < stone)
                        data[cx][cy][cz] = 2;
                    else if (y < dirt)
                        data[cx][cy][cz] = 3;
                    else if (y < grass)
                        data[cx][cy][cz] = 4;
                    */
                    else if (y < seaLevel)
                        data[cx][cy][cz] = 6;
                    else
                        data[cx][cy][cz] = 0;
                }
                else
                    data[cx][cy][cz] = 0;
            }
        }
    }
    this->generated = true;
}

bool Chunk::blockAir(int x, int y, int z)
{
    if (x < 0)
        return neighbours[0]->data[Settings::chunkSize + x][y][z] == 0;
    else if (x >= Settings::chunkSize)
        return neighbours[1]->data[Settings::chunkSize - x][y][z] == 0;
    else if (y < 0)
        return neighbours[2]->data[x][Settings::chunkSize + y][z] == 0;
    else if (y >= Settings::chunkSize)
        return neighbours[3]->data[x][Settings::chunkSize - y][z] == 0;
    else if (z < 0)
        return neighbours[4]->data[x][y][Settings::chunkSize + z] == 0;
    else if (z >= Settings::chunkSize)
        return neighbours[5]->data[x][y][Settings::chunkSize - z] == 0;
    else
        return data[x][y][z] == 0;
}

void Chunk::update()
{
    cubeCreator.clearData();
    int x, y, z;
    for (x = 0; x < Settings::chunkSize; x++)
    {
        for (y = 0; y < Settings::chunkSize; y++)
        {
            for (z = 0; z < Settings::chunkSize; z++)
            {
                if (data[x][y][z] != 0)
                {
                    if (blockAir(x - 1, y, z))
                        cubeCreator.left(glm::vec3(x, y, z),   glm::vec3(0.0f, 0.0f, 0.0f), data[x][y][z]);
                    if (blockAir(x + 1, y, z))
                        cubeCreator.right(glm::vec3(x, y, z),  glm::vec3(0.0f, 0.0f, 0.0f), data[x][y][z]);
                    if (blockAir(x, y - 1, z))
                        cubeCreator.bottom(glm::vec3(x, y, z), glm::vec3(0.0f, 0.0f, 0.0f), data[x][y][z]);
                    if (blockAir(x, y + 1, z))
                        cubeCreator.top(glm::vec3(x, y, z),    glm::vec3(0.0f, 0.0f, 0.0f), data[x][y][z]);
                    if (blockAir(x, y, z - 1))
                        cubeCreator.front(glm::vec3(x, y, z),  glm::vec3(0.0f, 0.0f, 0.0f), data[x][y][z]);
                    if (blockAir(x, y, z + 1))
                        cubeCreator.back(glm::vec3(x, y, z),   glm::vec3(0.0f, 0.0f, 0.0f), data[x][y][z]);
                }
            }
        }
    }
    if (cubeCreator.mesh.vertices.size() > 0)
    {
        cubeCreator.mesh.push();
    }
    else
    {
        invisible = true;
    }
}

void Chunk::render()
{
    if (!invisible)
        cubeCreator.mesh.render();
}

Chunk::~Chunk()
{
    //deleteData();
}


void Chunk::resetMesh()
{
    cubeCreator.clearData();
}
