#pragma once

#define PI 3.141592653f//58979323846264338327950288
#define DEG2RAD(x) ( (x)*( PI/ 180.f ) )
#define RAD2DEG(x) ( (x)*( 180.f/ PI ) )
#define FIXEDPOINT 12

namespace gba 
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
    unsigned short floatToFixed(float n);
    float fixedToFloat(unsigned short n);
    unsigned short radToLut(float a);

    float sin(float a);
    float cos(float a);
    float tan(float a);
    int floor(float n);
    float length(vec2 v);
    vec2 rotateVectorRad(vec2 v, float a);
    // float sqrt(float a);
}