#include <cmath>
#include <cstdint>
#include "config.hpp"


class ANFIS {
private:
    float m_input1;
    float m_input2;
    float m_input3;
    float m_modelParameters[INPUT_NUMBER][FUZZY_RULES][NUMBER_OF_MEMBERSHIP_FUNCTION_PARAMETERS] = PARAMETERS;

    float m_membershipFunctionOutArray[INPUT_NUMBER][FUZZY_RULES];
    float m_connectionsLayer[INPUT_NUMBER][(uint8_t)pow(FUZZY_RULES,INPUT_NUMBER)];
    float m_connectedLayers[(uint8_t)(pow(FUZZY_RULES, INPUT_NUMBER))];
    uint8_t m_weights[(uint8_t)pow(FUZZY_RULES,INPUT_NUMBER)] = WEIGHTS;
    float m_aggregationParameters[(uint8_t)pow(FUZZY_RULES,INPUT_NUMBER)] = AGREGATION_PARAMETERS;
    float m_aggregatedLayers[2][(uint8_t)(pow(FUZZY_RULES, INPUT_NUMBER))];
    float m_defuzzificated;

    void readInput(float FSR1, float FSR2, float FSR3);
    void fuzzifyInput();
    void connectLayers();
    void aggregation();
    void defuzzifyOutput();

public:
    ANFIS() = default;
    float classify(float FSR1, float FSR2, float FSR3);
};
