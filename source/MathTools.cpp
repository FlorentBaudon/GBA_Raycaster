#include "MathTools.h"
#include "sinlut.h"

#include <math.h>
#include <stdio.h>

int gba::floor(float n) 
{
    return (int)n;
}

float gba::cos(float a) 
{
    return gba::fixedToFloat(sin_table[gba::radToLut(a + PI/2)]);
}

float gba::sin(float a) //angle in radian
{
    return gba::fixedToFloat(sin_table[gba::radToLut(a)]);
}

float gba::tan(float a)
{
    return sin(a)/cos(a);
}

// float sqrt(float a) 
// {
//     float x,
//         x1 = a / 2;
        
//     do {
//         x = x1;
//         x1 = (x + (a / x)) / 2;
//     } while (x != x1);
//     return x;
// }

float gba::length(vec2 v) 
{
    float o = (v.x*v.x) + (v.y*v.y);
    return sqrt(o);
}

unsigned short gba::floatToFixed(float n)
{
    return (unsigned short)(n*(1 << FIXEDPOINT));
}

float gba::fixedToFloat(unsigned short n)
{
    return (float)((short)n)/(1 << FIXEDPOINT);
}

unsigned short gba::radToLut(float angle)
{
    // À optimiser
    short a = (short) (angle / (2 * PI / lut_size));
    a%=lut_size;
    a = (a>=0) ? a : (lut_size + a);
    return (unsigned short) a;
}

gba::vec2 gba::rotateVectorRad(vec2 v, float a) 
{
    float s = gba::sin(a);
    float c = gba::cos(a);
    return vec2(c * v.x  - s * v.y, s * v.x - c * v.y);
}


