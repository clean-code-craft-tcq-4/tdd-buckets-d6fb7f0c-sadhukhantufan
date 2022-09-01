#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sample_analyser.h"
#include "high_fidelity_current_sensor.h"
#include "charge_discharge_current_sensor.h"
using namespace std;

std::vector<std::string> checkRange(std::vector<int> input_sample)
{
  std::vector<string> rangeList;
  auto result = generateRange(input_sample, rangeList);
  return result;
}

// Start: Test Current Ranges
TEST_CASE("Test Sample 1")
{
  auto result_to_check = checkRange({4, 5});
  REQUIRE(result_to_check[0] == "[4-5] , 2");
}

TEST_CASE("Test Sample 2")
{
  auto result_to_check = checkRange({4, 5, 10});
  REQUIRE(result_to_check[0] == "[4-5] , 2");
  REQUIRE(result_to_check[1] == "[10-10] , 1");
}

TEST_CASE("Test Sample 3")
{
  auto result_to_check = checkRange({1, 4, 6, 7, 8, 10});
  REQUIRE(result_to_check[0] == "[1-1] , 1");
  REQUIRE(result_to_check[1] == "[4-4] , 1");
  REQUIRE(result_to_check[2] == "[6-8] , 3");
  REQUIRE(result_to_check[3] == "[10-10] , 1");
}

TEST_CASE("Test Sample 4")
{
  auto result_to_check = checkRange({1, 2, 3, 4, 5, 7, 8, 9, 13, 14, 15, 16, 17});
  REQUIRE(result_to_check[0] == "[1-5] , 5");
  REQUIRE(result_to_check[1] == "[7-9] , 3");
  REQUIRE(result_to_check[2] == "[13-17] , 5");
}

TEST_CASE("Test Sample 5")
{
  auto result_to_check = checkRange({});
  REQUIRE(result_to_check[0] == "Empty Input");
}

// End: Test Current Ranges

// Start : Test high_fidelity_current_sensor
TEST_CASE("test checkIf12BitArrayWithInRange : value within boundary")
{
  uint32_t currentSensorValue[] = {0, 1000, 2000, 3000, 4094};
  uint32_t sizeofSensorValue = sizeof(currentSensorValue) / sizeof(currentSensorValue[0]);
  bool status = checkIf12BitArrayWithInRange(currentSensorValue, sizeofSensorValue);
  REQUIRE(status == true);
}

TEST_CASE("test checkIf12BitArrayWithInRange : value > boundary")
{
  uint32_t currentSensorValue[] = {0, 1000, 2000, 3000, 5000};
  uint32_t sizeofSensorValue = sizeof(currentSensorValue) / sizeof(currentSensorValue[0]);
  bool status = checkIf12BitArrayWithInRange(currentSensorValue, sizeofSensorValue);
  REQUIRE(status == false);
}

TEST_CASE("test adc12BitCurrentValueToAmpere : value within boundary")
{
  uint32_t currentSensorValue[] = {500, 1146, 1500, 2000, 2500, 3000, 3500, 4000};
  uint32_t expectedCurrentValueInAmpere[] = {1, 3, 4, 5, 6, 7, 9, 10};
  auto sizeOfcurrentSensor = sizeof(currentSensorValue) / sizeof(currentSensorValue[0]);
  auto actual12BitCurrentValueInAmpere = adc12BitCurrentValueToAmpere(currentSensorValue, sizeOfcurrentSensor);
  for (uint32_t counter = 0; counter < sizeOfcurrentSensor; counter++)
  {
    REQUIRE(actual12BitCurrentValueInAmpere[counter] == expectedCurrentValueInAmpere[counter]);
  }
}

TEST_CASE("test adc12BitCurrentValueToAmpere : value > boundary")
{
  uint32_t currentSensorValue[] = {4095};
  auto sizeOfcurrentSensor = sizeof(currentSensorValue) / sizeof(currentSensorValue[0]);
  auto actual12BitCurrentValueInAmpere = adc12BitCurrentValueToAmpere(currentSensorValue, sizeOfcurrentSensor);
  bool currentInAmpereStatus = actual12BitCurrentValueInAmpere.empty();
  REQUIRE(currentInAmpereStatus == true);
}
// End : Test high_fidelity_current_sensor

// Start : Test charging_discharging_current_sensor
TEST_CASE("test checkIf10BitArrayWithInRange : value within boundary")
{
  int32_t currentSensorValue[] = {0, 100, 200, 300, 400, 512, 750, 1022};
  uint32_t sizeofSensorValue = sizeof(currentSensorValue) / sizeof(currentSensorValue[0]);
  bool status = checkIf10BitArrayWithInRange(currentSensorValue, sizeofSensorValue);
  REQUIRE(status == true);
}

TEST_CASE("test checkIf10BitArrayWithInRange : value < boundary")
{
  int32_t currentSensorValue[] = {-1, 100, 200, 300, 400, 512, 750, 1022};
  uint32_t sizeofSensorValue = sizeof(currentSensorValue) / sizeof(currentSensorValue[0]);
  bool status = checkIf10BitArrayWithInRange(currentSensorValue, sizeofSensorValue);
  REQUIRE(status == false);
}

TEST_CASE("test checkIf10BitArrayWithInRange : value > boundary")
{
  int32_t currentSensorValue[] = {0, 100, 200, 300, 400, 512, 750, 1023};
  uint32_t sizeofSensorValue = sizeof(currentSensorValue) / sizeof(currentSensorValue[0]);
  bool status = checkIf10BitArrayWithInRange(currentSensorValue, sizeofSensorValue);
  REQUIRE(status == false);
}

TEST_CASE("test adc10BitCurrentValueToAmpere : value within boundary")
{
  int32_t currentSensorValue[] = {0, 512, 1022};
  int32_t expectedCurrentValueInAmpere[] = {-15, 0, 15};
  auto sizeOfcurrentSensor = sizeof(currentSensorValue) / sizeof(currentSensorValue[0]);
  auto actual10BitCurrentValueInAmpere = adc10BitCurrentValueToAmpere(currentSensorValue, sizeOfcurrentSensor);
  for (uint32_t counter = 0; counter < sizeOfcurrentSensor; counter++)
  {
    REQUIRE(actual10BitCurrentValueInAmpere[counter] == expectedCurrentValueInAmpere[counter]);
  }
}

TEST_CASE("test adc10BitCurrentValueToAmpere : value out of boundary < lower boundary")
{
  int32_t currentSensorValue[] = {-1};
  auto sizeOfcurrentSensor = sizeof(currentSensorValue) / sizeof(currentSensorValue[0]);
  auto actual10BitCurrentValueInAmpere = adc10BitCurrentValueToAmpere(currentSensorValue, sizeOfcurrentSensor);
  bool currentInAmpereStatus = actual10BitCurrentValueInAmpere.empty();
  REQUIRE(currentInAmpereStatus == true);
}

TEST_CASE("test adc10BitCurrentValueToAmpere : value out of boundary > upper boundary")
{
  int32_t currentSensorValue[] = {1023};
  auto sizeOfcurrentSensor = sizeof(currentSensorValue) / sizeof(currentSensorValue[0]);
  auto actual10BitCurrentValueInAmpere = adc10BitCurrentValueToAmpere(currentSensorValue, sizeOfcurrentSensor);
  bool currentInAmpereStatus = actual10BitCurrentValueInAmpere.empty();
  REQUIRE(currentInAmpereStatus == true);
}
// End : Test charging_discharging_current_sensor
