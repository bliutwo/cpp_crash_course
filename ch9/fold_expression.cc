// A refactor of `variadic_template.cc` using a fold expression.

#include <cstdio>

template <typename... T>
constexpr auto sum(T... args) {
    return(... + args); // 1
}

int main() {
    printf("The answer is %d.", sum(2, 4, 6, 8, 10, 12));
}
