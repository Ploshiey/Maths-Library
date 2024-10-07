#include "vector.h"
#include <iostream>

int main()
{
    Vector2 v0(2, 3);
    Vector2 v1(4, 6);
    Vector2 v3 = v0 + v1;

    float firstElement = v1[0];
    float secondElement = v1[1];
}
