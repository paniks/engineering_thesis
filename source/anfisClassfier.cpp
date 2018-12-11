//
// Created by xavier on 08/11/17.
//

#include <cmath>
#include <cstdint>

#include <anfisClassfier.hpp>
#include <membershipFunctions.hpp>
#include <norms.hpp>
#include <defuzzificationMethods.hpp>


ANFIS::ANFIS()
{}

void ANFIS::readInput(float FSR1, float FSR2, float FSR3) {
    this->m_input1 = FSR1;
    this->m_input2 = FSR2;
    this->m_input3 = FSR3;
}

void ANFIS::fuzzifyInput() {

    for(uint8_t i = 0; i < INPUT_NUMBER; i++)
    {
        for(uint8_t j = 0; j < FUZZY_RULES; j++)
        {
            float x;
            if(i == 0) x = m_input1;
            else if (i == 1) x = m_input2;
            else x = m_input3;

            m_membershipFunctionOutArray[i][j] = gaussMF(x, m_modelParameters[i][j][0], m_modelParameters[i][j][1]);
        }
    }

}

void ANFIS::connectLayers() {


    // calculate membership array
    for (int i = 0; i < INPUT_NUMBER; i++)
    {
        int x = 1;
        for (uint8_t j = 0; j < pow(FUZZY_RULES, INPUT_NUMBER); j += pow(FUZZY_RULES, INPUT_NUMBER) / pow(FUZZY_RULES, i + 1))
        {
            for (uint8_t k = 0; k < pow(FUZZY_RULES, INPUT_NUMBER) / pow(FUZZY_RULES, i + 1); k++)
            {
                m_connectionsLayer[i][j + k] = m_membershipFunctionOutArray[i][x-1];
            }
            x += 1;
            if (x > FUZZY_RULES) x = 1;
        }
    }

    // connect layers
    for (uint8_t i = 0; i < pow(FUZZY_RULES, INPUT_NUMBER); i++)
    {
        m_connectedLayers[i] = (PROD(PROD(m_connectionsLayer[0][i], m_connectionsLayer[1][i]),
                                         m_connectionsLayer[2][i]))*m_weights[i];
    }
}

void ANFIS::aggregation() {
    for (uint8_t i = 0; i < pow(FUZZY_RULES, INPUT_NUMBER); i++)
    {
        m_agregatedLayers[0][i] = m_connectedLayers[i];
        m_agregatedLayers[1][i] = m_agregationParameters[i];
    }

}


void ANFIS::defuzzifyOutput() {
    m_defuzzificated = weightedAverage(m_agregatedLayers);
}

float ANFIS::classify(float FSR1, float FSR2, float FSR3) {
    readInput(FSR1, FSR2, FSR3);
    fuzzifyInput();
    connectLayers();
    aggregation();
    defuzzifyOutput();
    return m_defuzzificated;
}