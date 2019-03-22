#include "../headers/Blocks.h"

BlockPhysics::BlockPhysics() {}

BlockPhysics::BlockPhysics(bool translucent) {
    this->translucent = translucent;
}

BlockSide::BlockSide() {}

BlockSide::BlockSide(glm::ivec2 texture, BlockPhysics physics) {
    this->texture = texture;
    this->uvPos = glm::vec2(texture.x * Settings::uvUnit,
                            texture.y * Settings::uvUnit);
    this->physics = physics;
}

Block::Block(BlockSide left, BlockSide right, BlockSide bottom, BlockSide top, BlockSide front, BlockSide back) {
    this->left = left;
    this->right = right;
    this->bottom = bottom;
    this->top = top;
    this->front = front;
    this->back = back;
}

Block Blocks::block[6] = {

    Block(BlockSide(glm::vec2(-1, -1), BlockPhysics(true)), // air
          BlockSide(glm::vec2(-1, -1), BlockPhysics(true)),
          BlockSide(glm::vec2(-1, -1), BlockPhysics(true)),
          BlockSide(glm::vec2(-1, -1), BlockPhysics(true)),
          BlockSide(glm::vec2(-1, -1), BlockPhysics(true)),
          BlockSide(glm::vec2(-1, -1), BlockPhysics(true))),

    Block(BlockSide(glm::vec2(0, 0), BlockPhysics(false)), // bedrock
          BlockSide(glm::vec2(0, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(0, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(0, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(0, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(0, 0), BlockPhysics(false))),

    Block(BlockSide(glm::vec2(1, 0), BlockPhysics(false)), // stone
          BlockSide(glm::vec2(1, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(1, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(1, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(1, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(1, 0), BlockPhysics(false))),

    Block(BlockSide(glm::vec2(2, 0), BlockPhysics(false)), // dirt
          BlockSide(glm::vec2(2, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(2, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(2, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(2, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(2, 0), BlockPhysics(false))),

   /* Block(BlockSide(glm::vec2(4, 0), BlockPhysics(false)), // grass
          BlockSide(glm::vec2(4, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(4, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(4, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(4, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(4, 0), BlockPhysics(false))),*/

    Block(BlockSide(glm::vec2(3, 0), BlockPhysics(false)), // minecraft grass
          BlockSide(glm::vec2(3, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(2, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(4, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(3, 0), BlockPhysics(false)),
          BlockSide(glm::vec2(3, 0), BlockPhysics(false))),

    Block(BlockSide(glm::vec2(9, 0), BlockPhysics(true)), // water
          BlockSide(glm::vec2(9, 0), BlockPhysics(true)),
          BlockSide(glm::vec2(9, 0), BlockPhysics(true)),
          BlockSide(glm::vec2(9, 0), BlockPhysics(true)),
          BlockSide(glm::vec2(9, 0), BlockPhysics(true)),
          BlockSide(glm::vec2(9, 0), BlockPhysics(true)))
};
