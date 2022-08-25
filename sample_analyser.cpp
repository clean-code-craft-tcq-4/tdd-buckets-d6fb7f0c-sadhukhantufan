#include "sample_analyser.h"
using namespace std;

void generateRangeAndPrintOutput(std::vector<int> input_sample)
{
  uint8_t i;
  int count = 0;
  std::vector<int> range;
  printOutput(range, count, header);

  if (!input_sample.empty())
  {
    for (i = 0; i < input_sample.size(); ++i)
    {

      if (count == 0)
      {
        range.push_back(input_sample[i]);
      }

      if (input_sample[i + 1] == input_sample[i] + 1)
      {
        range.push_back(input_sample[i + 1]);
        count++;
      }
      else
      {
        printOutput(range, count, rangeReader);
        range.clear();
        count = 0;
      }
    }

    printOutput(range, count, footer);
  }
  else
  {
    std::cout << "Empty Input !!!" << std::endl;
  }
}

void printOutput(std::vector<int> range, int count, int print_expression)
{
  switch (print_expression)
  {
  case header: // Prints Header
    std::cout << "|   RANGE   |   READINGS   |" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    break;
  case footer: // Prints Footer
    std::cout << "----------------------------------------" << std::endl;
    break;
  case rangeReader: // Prints Range, Readings Output
    std::cout << "|   " << *min_element(range.begin(), range.end()) << "-" << *max_element(range.begin(), range.end()) << ","
              << "\t " << count + 1 << std::endl;
    break;
  }
}
