#pragma once

#define PI 3.141592653f//58979323846264338327950288
#define DEG2RAD(x) ( (x)*( PI/ 180.f ) )
#define RAD2DEG(x) ( (x)*( 180.f/ PI ) )
#define FIXEDPOINT 8

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

    /***** Convert functions *****/
    // Fixed value
    int16 floatToFixed(float n);
    float fixedToFloat(int16 n);
    // Unsigned fixed values
    uint16 floatToUFixed(float n);
    float uFixedToFloat(uint16 n);
    //////////
    uint16 radToLut(float a);

    float sin(float a);
    float cos(float a);
    float tan(float a);
    int16 floor(float n);
    float length(vec2 v);
    vec2 rotateVectorRad(vec2 v, float a);
    float sqrt(float x);
}