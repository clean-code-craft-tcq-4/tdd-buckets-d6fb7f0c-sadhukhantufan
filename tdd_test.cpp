#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "tdd.h"
using namespace std;

// As a first step, only considering to detect continuous ranges in the samples
TEST_CASE("TEST CASE 1")
{
  std::vector<int> Current_Samples = {4, 5};
  auto Current_Samples_size = Current_Samples.size();
  range(Current_Samples, Current_Samples_size);
}

TEST_CASE("TEST CASE 2")
{
  std::vector<int> Current_Samples = {4, 5, 10};
  auto Current_Samples_size = Current_Samples.size();
  range(Current_Samples, Current_Samples_size);
}

TEST_CASE("TEST CASE 3")
{
  std::vector<int> Current_Samples = {1, 4, 6, 7, 8, 10};
  auto Current_Samples_size = Current_Samples.size();
  range(Current_Samples, Current_Samples_size);
}

TEST_CASE("TEST CASE 4")
{
  std::vector<int> Current_Samples = {1, 4, 6, 7, 8, 10};
  auto Current_Samples_size = Current_Samples.size();
  range(Current_Samples, Current_Samples_size);
}

TEST_CASE("TEST CASE 5")
{
  std::vector<int> Current_Samples = {1, 2, 3, 4, 5, 7, 8, 9, 13, 14, 15, 16, 17};
  auto Current_Samples_size = Current_Samples.size();
  range(Current_Samples, Current_Samples_size);
}
