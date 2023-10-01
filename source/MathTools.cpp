#include "MathTools.h"
#include "sinlut.h"
#include <math.h>
#include <stdio.h>

int m_gba::floor(float n) 
{
    return (int)n;
}

float m_gba::cos(float a) 
{
    return m_gba::fixedToFloat(sin_table[m_gba::radToLut(a + PI/2)]);
}

float m_gba::sin(float a) //angle in radian
{
    return m_gba::fixedToFloat(sin_table[m_gba::radToLut(a)]);
}

float m_gba::tan(float a)
{
    return sin(a)/cos(a);
}

 uint32 m_gba::sqrti(uint32 num)
{  
    asm ("swi 0x08");
}

int m_gba::div(int num, int denom)
{   
    asm("swi 0x06");   
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

float m_gba::length(vec2 v) 
{
    uint32 o = uint32((v.x*v.x) + (v.y*v.y));

    return sqrt(o);
}

uint16 m_gba::floatToFixed(float n)
{
    return (uint16)(n*(1 << FIXEDPOINT));
}

float m_gba::fixedToFloat(uint16 n)
{
    return (float)((short)n)/(1 << FIXEDPOINT);
}

uint16 m_gba::radToLut(float angle)
{
    // À optimiser
    short a = (short) (angle / (2 * PI / lut_size));
    a%=lut_size;
    a = (a>=0) ? a : (lut_size + a);
    return (uint16) a;
}

m_gba::vec2 m_gba::rotateVectorRad(vec2 v, float a) 
{
    float s = m_gba::sin(a);
    float c = m_gba::cos(a);
    return vec2(c * v.x  - s * v.y, s * v.x - c * v.y);
}


