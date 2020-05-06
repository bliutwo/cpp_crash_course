// Using a std::function array to iterate over a uniform collection of callable
// objects with varying underlying types

#include <cstdio>
#include <cstdint>
#include <functional>

struct CountIf {
    CountIf(char x) : x{ x } { }
    size_t operator()(const char* str) const {
        size_t index{}, result{};
        while (str[index]) {
            if (str[index] == x) result++;
            index++;
        }
        return result;
    }
private:
    const char x;
};

size_t count_spaces(const char* str) {
    size_t index{}, result{};
    while (str[index]) {
        if (str[index] == ' ') result++;
        index++;
    }
    return result;
}

std::function/*1*/<size_t(const char*)/*2*/> funcs[] {
    count_spaces, // 3
    CountIf{ 'e' }, // 4
    [](const char* str) { // 5
        size_t index{};
        while(str[index]) index++;
        return index;
    }
};

auto text = "Sailor went to sea to see what he could see.";

int main() {
    size_t index{};
    for(const auto& func : funcs /*6*/) {
        printf("func #%zd: %zd\n", index++, func(text) /*7*/);
    }
}
