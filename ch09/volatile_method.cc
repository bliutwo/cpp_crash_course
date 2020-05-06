#include <cstdio>

struct Distillate {
    int apply() volatile /*1*/ {
        return ++applications;
    }
private:
    int applications{};
};

int main() {
    volatile /*2*/ Distillate ethanol;
    printf("%d Tequila\n", ethanol.apply() /*3*/);
    printf("%d Tequila\n", ethanol.apply());
    printf("%d Tequila\n", ethanol.apply());
    printf("Floor!");
}
