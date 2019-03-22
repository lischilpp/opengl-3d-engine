#include <GLM/glm.hpp>
#include "Settings.h"

struct BlockPhysics
{
    bool translucent;
    BlockPhysics(bool translucent);
    BlockPhysics();
};

struct BlockSide
{
    glm::ivec2 texture;
    glm::vec2 uvPos;
    BlockPhysics physics;
    BlockSide(glm::ivec2 texture, BlockPhysics physics);
    BlockSide();
};

struct Block
{
    BlockSide left, right, bottom, top, front, back;
    Block(BlockSide left, BlockSide right, BlockSide bottom, BlockSide top, BlockSide front, BlockSide back);
};

class Blocks
{
public:
    static Block block[6];
};
