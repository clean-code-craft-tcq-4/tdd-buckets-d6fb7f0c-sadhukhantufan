#ifndef CHARGE_DISCHARGE_CURRENT_SENSOR
#define CHARGE_DISCHARGE_CURRENT_SENSOR

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define ADC_10BIT_UPPER_LIMIT (1022)
#define ADC_10BIT_LOWER_LIMIT (0)
#define ADC_10BIT_MAX_CURRENT_IN_AMPS (15)

bool checkIf10BitArrayWithInRange(int32_t *arrayForTest, uint32_t sizeOfArray);
vector<int32_t> adc10BitCurrentValueToAmpere(int32_t *currentSensorValue, uint32_t sizeOfcurrentSensor);

#endif // CHARGE_DISCHARGE_CURRENT_SENSOR