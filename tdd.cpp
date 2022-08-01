#include <iostream>
#include <algorithm>
#include "tdd.h"
using namespace std;

void range(int array[], int size)
{
  int i, count = 0;
  int range[10] = {0};

  for (i = 0; i < size; i++)
  {

    if (array[i + 1] == array[i] + 1)
    {
      range[count] = array[i];
      count++;
    }
    else
    {
      // std::pair<int *, int *> minmax = std::minmax_element(std::begin(range), std::end(range));
      // std::cout << "range is (" << *(minmax.first) << "," << *(minmax.second) << ")" << std::endl;
      std::cout << "range is (" << *min_element(range, range + size) << "," << *max_element(range, range + size) << ")" << std::endl;
      std::cout << "Readings " << count + 1 << std::endl;
    }
  }
}

int main()
{
  int test_array[5] = {1, 2, 3, 4, 5};
  int size = sizeof(test_array) / sizeof(test_array[0]);
  range(test_array, size);
  return 0;
}
