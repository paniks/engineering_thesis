#include <cmath>
#include <norms.hpp>

float MIN(float a, float b)
{
    return fminf(a, b);
}

float MAX(float a, float b)
{
    return fmaxf(a, b);
}

float PROD(float a, float b)
{
    return a*b;
}

float ALGSUM(float a, float b)
{
    return a + b - (a*b);
}