// A refactor of `variadic_function.cc` using a template parameter pack instead
// of va_args

#include <cstdio>

template <typename T>
constexpr /*1*/ T sum(T x) { // 2
    return x;
}

template <typename T, typename... Args>
constexpr /*3*/ T sum(T x, Args... args) { // 4
    return x + sum(args... /*5*/);
}

int main() {
    printf("The answer is %d.", sum(2, 4, 6, 8, 10, 12)); // 6
}
