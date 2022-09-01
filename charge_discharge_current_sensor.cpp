#include "charge_discharge_current_sensor.h"

using namespace std;

bool checkIf10BitArrayWithInRange(int32_t *arrayForTest, uint32_t sizeOfArray)
{
  for (uint32_t counter = 0; counter < sizeOfArray; counter++)
  {
    if ((arrayForTest[counter] > ADC_10BIT_UPPER_LIMIT) || (arrayForTest[counter] < ADC_10BIT_LOWER_LIMIT))
    {
      return false;
    }
  }
  return true;
}

vector<int32_t> adc10BitCurrentValueToAmpere(int32_t *currentSensorValue, uint32_t sizeOfcurrentSensor)
{
  std::vector<int32_t> currentInAmpereList;
  if ((sizeOfcurrentSensor != 0) && (checkIf10BitArrayWithInRange(currentSensorValue, sizeOfcurrentSensor)))
  {
    for (uint32_t counter = 0; counter < sizeOfcurrentSensor; counter++)
    {
      int32_t roundOfValue = round((2 * ADC_10BIT_MAX_CURRENT_IN_AMPS * static_cast<float>(currentSensorValue[counter]) / ADC_10BIT_UPPER_LIMIT) - (ADC_10BIT_MAX_CURRENT_IN_AMPS));
      currentInAmpereList.push_back(static_cast<int32_t>(roundOfValue));
    }
  }
  return currentInAmpereList;
}