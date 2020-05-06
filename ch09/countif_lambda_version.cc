// Reformulating CountIf from `countif.cc ` as a lambda

#include <cstdio>
#include <cstdint>

int main() {
    char to_count{ 's' }; // 1
    auto s_counter = [to_count /*2*/](const char* str) {
        size_t index{}, result{};
        while (str[index]) {
            if (str[index] == to_count /*3*/) result++;
            index++;
        }
        return result;
    };
    auto sally = s_counter("Sally sells seashells by the seashore." /*4*/);
    printf("Sally: %zd\n", sally);
    auto sailor = s_counter("Sailor went to sea to see what he could see.");
    printf("Sailor: %zd\n", sailor);
    return 0;
}
