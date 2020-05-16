#include <cstdio>
#include <array>

int main() {
  unsigned long maximum = 0;
  std::array<unsigned long, 5> values{ 10, 50, 20, 40, 0 };
  for(unsigned long value : values) {
    if(value > maximum)
      maximum = value;
  }
  printf("The maximum value is %lu.\n", maximum);
}
