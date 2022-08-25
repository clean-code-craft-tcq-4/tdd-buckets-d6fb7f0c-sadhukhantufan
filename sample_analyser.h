#include <iostream>
#include <vector>
#include <algorithm>

void generateRangeAndPrintOutput(std::vector<int> input_sample);
void printOutput(std::vector<int> range, int count, int print_expression);

enum PrintExpression
{
    header,
    footer,
    rangeReader
};