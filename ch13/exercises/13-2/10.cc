#include <cstdio>
#include <array>

int main() {
    unsigned long maximum = 0;
    std::array<unsigned long, 5> values{ 10, 50, 20, 40, 0 };
    for(size_t i = 0; i < 5; i++) {
      if(values[i] > maximum)
        maximum = values[i];
    }
    printf("The maximum value is %lu.\n", maximum);
}