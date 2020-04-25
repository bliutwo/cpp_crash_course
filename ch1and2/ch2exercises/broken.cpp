#include <cstdio>

enum class Operation {
    int x;
    int y;
    Operation() {
        x = 0;
        y = 0;
    }
    Operation(int a, int b) {
        x = a;
        y = b;
    }
    Add() {
        return x + y;
    }
    Subtract() {
        return x - y;
    }
    Multiply() {
        return x * y;
    }
    Divide() {
        return x / y;
    }
};

int main() {
    Operation o {1, 2};
    printf("%d\n", o.add());
}
