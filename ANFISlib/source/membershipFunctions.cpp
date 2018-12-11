#include <cmath>

#include <membershipFunctions.hpp>

float gaussMF(float x, float sigma, float mi) {
    auto base = (float)exp(1);
    auto exponent = (float)(-pow(x - mi ,2))/(2*pow(sigma, 2));

    return (float)pow(base, exponent);
}