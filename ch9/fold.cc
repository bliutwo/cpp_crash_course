#include <cstdio>
#include <limits>

template <typename Fn, typename In, typename Out>
constexpr Out fold(Fn function, In* input, size_t length, Out initial)
{
    if (length == 0) {
        return initial;
    }
    Out last_element = input[length - 1];
    return function(initial, fold(function, input, length - 1, last_element));
}

int main() {
    int data[]{ 100, 200, 300, 400, 500 };
    size_t data_len = 5;

    auto sum = fold([](auto x, auto y) { return x + y; }, data, data_len, 0);
    printf("Sum: %d\n", sum);

    int inf = std::numeric_limits<int>::infinity();
    auto max = fold([](auto x, auto y) { return x > y ? x : y; }, data, data_len, -1 * inf);
    printf("Max: %d\n", max);

    auto min = fold([](auto x, auto y) { return x < y ? x : y; }, data, data_len, inf);
    printf("Min: %d\n", min);

    return 0;
}
