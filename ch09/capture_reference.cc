#include <cstdio>
#include <cstdint>

int main() {
    char to_count{ 's' };
    size_t tally{}; // 1
    auto s_counter = [to_count, &tally /*2*/](const char* str) {
        size_t index{}, result{};
        while (str[index]) {
            if (str[index] == to_count) result++;
            index++;
        }
        tally += result; // 3
        return result;
    };
    printf("Taly: %zd\n", tally); // 4
    auto sally = s_counter("Sally sells seashells by the seashore.");
    printf("Sally: %zd\n", sally);
    printf("Tally: %zd\n", tally); // 5
    auto sailor = s_counter("Sailor went to sea to see what he could see.");
    printf("Sailor: %zd\n", sailor);
    printf("Tally: %zd\n", tally); // 6
    return 0;
}
