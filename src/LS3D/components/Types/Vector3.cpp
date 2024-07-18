#include "LS3D/components/Types/Vector3.h"

Vector3::Vector3() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
};

Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector3::Distance(Vector3 a, Vector3 b)
{
    return sqrt((b.x - a.x) * (b.x - a.x)+
                (b.y - a.y) * (b.y - a.y)+
                (b.z - a.z) * (b.z - a.z));
}
