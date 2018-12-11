#include <defuzzificationMethods.hpp>

float weightedAverage(float array[2][(uint8_t)pow(FUZZY_RULES, INPUT_NUMBER)]) {
    float weight_sum = 0;
    float top = 0;

    for (uint8_t i = 0; i < pow(FUZZY_RULES, INPUT_NUMBER); i++) {
        top += array[0][i] * array[1][i];
        weight_sum += array[0][i];
    }

    return top / weight_sum;
}
