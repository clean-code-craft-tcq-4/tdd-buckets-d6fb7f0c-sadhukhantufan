#include "sample_analyser.h"
using namespace std;

std::vector<std::string> generateRange(std::vector<int> input_sample, std::vector<std::string> rangeList)
{
  uint8_t i;
  int count = 0;
  std::vector<int> range;
  // std::vector<string> rangeList;
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
        rangeLimit m_obj;
        printOutput(range, count, rangeReader);
        auto boundaryValue = findMaxMin(range, m_obj);
        string dataElement = "[" + to_string(boundaryValue.min) + "-" + to_string(boundaryValue.max) + "] , " + to_string(count + 1);
        rangeList.push_back(dataElement);
        range.clear();
        count = 0;
      }
    }

    printOutput(range, count, footer);
  }
  else
  {
    std::string no_output = "Empty Input";
    std::cout << no_output << std::endl;
    rangeList.push_back("Empty Input");
  }
  return rangeList;
}

rangeLimit findMaxMin(std::vector<int> range, rangeLimit boundary)
{
  boundary.max = *max_element(range.begin(), range.end());
  boundary.min = *min_element(range.begin(), range.end());

  return boundary;
}

void printOutput(std::vector<int> range, int count, int print_expression)
{
  rangeLimit l_obj;
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
    auto boundaryValue = findMaxMin(range, l_obj);
    std::cout << "|   " << boundaryValue.min << "-" << boundaryValue.max << ","
              << "\t " << count + 1 << std::endl;
    break;
  }
}
