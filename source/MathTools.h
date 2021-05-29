#pragma once

#define PI 3.14159265358979323846264338327950288
#define DEG2RAD(x) ( (x)*( PI/ 180.f ) )
#define RAD2DEG(x) ( (x)*( 180.f/ PI ) )

namespace gba 
{
    struct vec2 
    {
        int x;
        int y;
        vec2()
        {
            x = 0;
            y = 0;
        }
        vec2(int _x, int _y) 
        {
            x = _x;
            y = _y;
        }
        vec2 operator+(const vec2 a)
        {
            return vec2(x+a.x, y+a.y);
        }
        vec2 operator-(const vec2 a)
        {
            return vec2(x-a.x, y-a.y);
        }
    };

    struct vec2f
    {
        float x;
        float y;
    };

    float sin(float a);
    float cos(float a);
    float tan(float a);
    int floor(float n);
    float vec_length(vec2 v);
    // float sqrt(float a);
}