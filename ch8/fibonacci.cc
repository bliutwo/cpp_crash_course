#include <cstdio>

struct FibonacciIterator {
    bool operator!=(int x) const {
        return x >= current; // 1
    }

    FibonacciIterator& operator++() {
        const auto tmp = current; // 2
        current += last; // 3
        last = tmp; // 4
        return *this; // 5
    }

    int operator*() const {
        return current; // 6
    }
private:
    int current{ 1 }, last{ 1 };
};

struct FibonacciRange {
    explicit FibonacciRange(int max /* 7 */) : max{ max } { }
    FibonacciIterator begin() const { // 8
        return FibonacciIterator{};
    }
    int end() const { // 9
        return max;
    }
private:
    const int max;
};

int main() {
    for (const auto i : FibonacciRange{ 5000 } /*1*/) {
        printf("%d ", i); // 2
    }
    printf("\n");
    return 0;
}
