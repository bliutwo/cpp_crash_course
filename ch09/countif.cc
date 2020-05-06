// A function type that counts the number of characters appearing in a null-
// terminated string.

#include <cstdio>
#include <cstdint>

struct CountIf {
    CountIf(char x) : x{ x } { } // 1
    size_t operator()(const char* str /*2*/) const {
        size_t index{}/*3*/, result{};
        while (str[index]) {
            if (str[index] == x) result++; // 4
            index++;
        }
        return result;
    }
private:
    const char x;
};

// A free function emulating CountIf
size_t count_if(char x, const char* str) {
    size_t index{}, result{};
    while (str[index]) {
        if (str[index] == x) result++;
        index++;
    }
    return result;
}

int main1() {
    CountIf s_counter{ 's' }; // 5
    auto sally = s_counter("Sally sells seashells by the seashore."); // 6
    printf("Sally: %zd\n", sally);
    auto sailor = s_counter("Sailor went to the sea to see what he could see.");
    printf("Sailor: %zd\n", sailor);
    auto buffalo = CountIf{ 'f' }("Buffalo buffalo Buffalo buffalo "
                                  "buffalo buffalo Buffalo buffalo."); // 7
    printf("Buffalo: %zd\n", buffalo);
    return 0;
}

int main() {
    auto sally = count_if('s', "Sally sells seashells by the seashore.");
    printf("Sally: %zd\n", sally);
    auto sailor = count_if('s', "Sailor went to sea to see what he could see.");
    printf("Sailor: %zd\n", sailor);
    auto buffalo = count_if('f', "Buffalo buffalo Buffalo buffalo "
                                 "buffalo buffalo Buffalo buffalo.");
    printf("Buffalo: %zd\n", buffalo);
    return 0;
}
