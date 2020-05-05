// Using a generic lambda

#include <cstdio>
#include <cstdint>

template <typename Fn, typename T /*1*/>
void transform(Fn fn, const T* in, T* out, size_t len) {
    for (size_t i{}; i < len; i++) {
        out[i] = fn(in[i]);
    }
}

int main() {
    constexpr size_t len{ 3 };
    int base_int[]{ 1, 2, 3 }, a[len]; // 2
    float base_float[]{ 10.f, 20.f, 30.f }, b[len]; // 3
    auto translate = [](auto x) { return 10 * x + 5; }; // 4
    transform(translate, base_int, a, len); // 5
    transform(translate, base_float, b, len); // 6

    for (size_t i{}; i < len; i++) {
        printf("Element %zd: %d %f\n", i, a[i], b[i]);
    }
    return 0;
}
