#include <glm/glm.hpp>
#include <memory>
#include "../../utility/headers/Vector3i.h"
#include "../../utility/headers/Random.h"
#include "../../utility/noise/headers/Noise.h"
#include  "../../utility/headers/Debug.h"
//#include "CubeCreator.h"

class Chunk
{
public:
    glm::ivec3 chunkIndex;
    glm::ivec3 chunkPosition;
    bool busy, generated, preparedToRender, rendered, inRenderDistance, invisible;
    std::shared_ptr<Chunk> neighbours[6];
    int generatedNeighbourCount, renderedNeighbourCount;

    Chunk();
    void initData();
    void deleteData();
    void generate();
    void render();
    void update();
    void setChunkIndex(glm::ivec3 chunkIndex);
    void resetMesh();
    ~Chunk();
private:
    CubeCreator cubeCreator;
    int data[Settings::chunkSize][Settings::chunkSize][Settings::chunkSize];
    bool blockAir(int x, int y, int z);
};
