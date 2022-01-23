#include "GBA_VAR.h"

#include "MathTools.h"
#include "sinlut.h"

extern "C" int asm_sqrt(int x) CODE_IN_IWRAM;

int16 gba::floor(float n) 
{
    return (int16)n;
}

float gba::cos(float a) 
{
    return gba::uFixedToFloat(sin_table[gba::radToLut(a + PI/2)]);
}

float gba::sin(float a) //angle in radian
{
    return gba::uFixedToFloat(sin_table[gba::radToLut(a)]);
}

float gba::tan(float a)
{
    return gba::sin(a)/gba::cos(a);
}

float gba::sqrt(float x) 
{
    return asm_sqrt(x);
}

float gba::length(vec2 v) 
{
    float o = (v.x*v.x) + (v.y*v.y);
    return gba::sqrt(o);
}


int16 gba::floatToFixed(float n)
{
    return (int16)(n*(1 << FIXEDPOINT));
}

float gba::fixedToFloat(int16 n)
{
    return (float)((int16)n)/(1 << FIXEDPOINT);
}

uint16 gba::floatToUFixed(float n)
{
    return (uint16)(n*(1 << FIXEDPOINT));
}

float gba::uFixedToFloat(uint16 n)
{
    return (float)((int16)n)/(1 << FIXEDPOINT);
}

uint16 gba::radToLut(float angle)
{
    // À optimiser
    int16 a = (int16) (angle / (2 * PI / lut_size));
    a%=lut_size;
    a = (a>=0) ? a : (lut_size + a);
    return (uint16) a;
}

gba::vec2 gba::rotateVectorRad(vec2 v, float a) 
{
    float s = gba::sin(a);
    float c = gba::cos(a);
    return vec2(c * v.x  - s * v.y, s * v.x - c * v.y);
}


