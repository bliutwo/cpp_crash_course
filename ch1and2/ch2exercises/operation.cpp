#include <cstdio>

enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

struct Calculator {
    Operation o;
    Calculator(Operation op) {
        o = op;
    }
    int calculate(int a, int b) {
        if (o == Operation::Add)
            return a + b;
        else if (o == Operation::Subtract)
            return a - b;
        else if (o == Operation::Multiply)
            return a * b;
        else
            return a / b;
    }
};

int main() {
    Operation o = Operation::Divide;
    Calculator c = Calculator(o);
    printf("%d\n", c.calculate(2, 3));
    return 0;
}
