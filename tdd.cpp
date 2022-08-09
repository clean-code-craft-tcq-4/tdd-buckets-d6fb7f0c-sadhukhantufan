#include "tdd.h"
using namespace std;

void range(std::vector<int> array, std::size_t size)
{
  uint8_t i;
  int count = 0;
  std::vector<int> range;

  for (i = 0; i < size; ++i)
  {

    if (count == 0)
    {
      range.push_back(array[i]);
    }

    if (array[i + 1] == array[i] + 1)
    {
      range.push_back(array[i + 1]);
      count++;
    }
    else
    {
      std::cout << "range is (" << *min_element(range.begin(), range.end()) << "," << *max_element(range.begin(), range.end()) << ")" << std::endl;
      std::cout << "Readings " << count + 1 << std::endl;
      range.clear();
      count = 0;
    }
  }
}

// int main()
// {
  // std::vector<int> test_array = {1, 2, 3, 4, 5, 7, 8, 9, 13, 14, 15, 16, 17};
  // auto size = test_array.size();
  // range(test_array, size);
  // return 0;
// }
