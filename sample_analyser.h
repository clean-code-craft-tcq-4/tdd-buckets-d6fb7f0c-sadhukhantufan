#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> generateRange(std::vector<int> input_sample, std::vector<std::string> rangeList);
void printOutput(std::vector<int> range, int count, int print_expression);

enum PrintExpression
{
    header,
    footer,
    rangeReader
};

struct rangeLimit
{
    int max{0};
    int min{0};
};

rangeLimit findMaxMin(std::vector<int> range, rangeLimit boundary);