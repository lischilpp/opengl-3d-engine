#include "Vector2.h"

float Vector2::Distance(Vector2 a, Vector2 b)
{
    return sqrt((b.x - a.x) * (b.x - a.x)+
                (b.y - a.y) * (b.y - a.y));
}

Vector2::Vector2()
{
    this->x = 0;
    this->y = 0;
}

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}
