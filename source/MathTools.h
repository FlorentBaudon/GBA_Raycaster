#pragma once

#include "GBA_VAR.h"

#define PI 3.141592653f//58979323846264338327950288
#define DEG2RAD(x) ( (x)*( PI/ 180.f ) )
#define RAD2DEG(x) ( (x)*( 180.f/ PI ) )
#define FIXEDPOINT 12

namespace m_gba 
{
    struct vec2 
    {
        float x;
        float y;
        vec2()
        {
            x = 0;
            y = 0;
        }
        vec2(float _x, float _y) 
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

    //convert functions
    uint16 floatToFixed(float n);
    float fixedToFloat(uint16 n);
    uint16 radToLut(float a);

    float sin(float a);
    float cos(float a);
    float tan(float a);
    int floor(float n);
    float length(vec2 v);
    vec2 rotateVectorRad(vec2 v, float a);
    // float sqrt(float a);
}