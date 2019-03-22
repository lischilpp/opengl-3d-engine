#include "../../utility/headers/Math.h"
#include "Chunk.h"
#include "Player.h"
#include "ChunkMap.h"
#include <set>
#include <memory>
#include <list>

class ChunkManager
{
public:
    ChunkMap chunks;
    ChunkSet createdChunks;
    ChunkSet generatedChunks;
    list<std::shared_ptr<Chunk>> renderedChunks;

    ChunkManager(Player* player, Time* time);
    void init();
    void render();
    void update();
private:
    Player* player;
    Time* time;
    glm::ivec3 getPlayerChunkIndex();
    glm::ivec3 playerChunkIndex;
    int chunkLoadsPerFrame, chunkLoadsThisFrame, chunkUpdatesPerFrame, chunkUpdatesThisFrame, framerate, passedFrames;

    void createChunk(glm::ivec3 chunkIndex);
    void createChunkNeighbours(std::shared_ptr<Chunk> chunk);
    void generateChunk(std::shared_ptr<Chunk> chunk);
    void generateChunkThread(std::shared_ptr<Chunk> chunk);
    void prepareChunkToRender(std::shared_ptr<Chunk> chunk);
    void degenerateChunk(std::shared_ptr<Chunk> chunk);
    void derenderChunk(std::shared_ptr<Chunk> chunk);
    void unloadChunk(std::shared_ptr<Chunk> chunk);
    void deleteChunk(std::shared_ptr<Chunk> chunk);
    void loadChunksAroundPlayer();
};
