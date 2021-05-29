#include "MathTools.h"
#include "trig.h"

#include <math.h>

int gba::floor(float n) 
{
    return (int)n;
}

float gba::cos(float a) 
{
    return cos_table[(int)RAD2DEG(a)];
}

float gba::sin(float a) 
{
    return sin_table[(int)RAD2DEG(a)];
}

float gba::tan(float a)
{
    return tan_table[(int)RAD2DEG(a)];
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

float gba::vec_length(vec2 v) 
{
    float o = (v.x*v.x) + (v.y*v.y);
    return sqrt(o);
}


