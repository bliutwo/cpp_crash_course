// Three lambdas and a transform function

#include <cstdio>
#include <cstdint>

template <typename Fn>
void transform(Fn fn, const int* in, int* out, size_t length) { // 1
    for (size_t i{}; i < length; i++) {
        out[i] = fn(in[i]); // 2
    }
}

int main() {
    const size_t len{ 3 };
    int base[]{ 1, 2, 3 }, a[len], b[len], c[len];
    transform([](int x) { return 1; } /*3*/, base, a, len);
    transform([](int x) { return x; } /*4*/, base, b, len);
    transform([](int x) { return 10*x+5; } /*5*/, base, c, len);
    for (size_t i{}; i < len; i++) {
        printf("Element %zd: %d %d %d\n", i, a[i], b[i], c[i]);
    }
    return 0;
}
