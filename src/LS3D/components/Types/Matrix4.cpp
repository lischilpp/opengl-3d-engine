#include "LS3D/components/Types/Matrix4.h"

float& Matrix4::Matrix4::operator[](int i)
{
    return data[i];
}


float Matrix4::identity[16] = { 1, 0, 0, 0,
                                0, 1, 0, 0,
                                0, 0, 1, 0,
                                0, 0, 0, 1 };

Matrix4::Matrix4()
{
    memcpy(data, Matrix4::identity, sizeof(data));
}
