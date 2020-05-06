// A program with a class attempting to inherit from a final class. (This code
// doesn't compile.)
#include <cstdio>

struct BostonCorbett final /*1*/{
    virtual void shoot() {
        printf("What a God we have...God avenged Abraham Lincoln");
    }
};

struct BostonCorbettJunior : BostonCorbett { };

int main() {
    BostonCorbettJunior junior;
}
