#include "is_prime.h"
#include <math.h>

struct PrimeNumberIterator {
    bool operator!=(int x) const {
        return x >= current;
    }

    PrimeNumberIterator& operator++() {
        do {
            current++;
        } while (!is_prime(current));
        return *this;
    }

    int operator*() const {
        return current;
    }
private:
    int current{ 2 };
};

struct PrimeNumberRange {
    explicit PrimeNumberRange(int max) : max{ max } { }
    PrimeNumberIterator begin() const {
        return PrimeNumberIterator{};
    }
    int end() const {
        return max;
    }
private:
    const int max;
};
