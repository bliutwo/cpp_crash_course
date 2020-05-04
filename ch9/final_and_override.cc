// A class attempting to override a final method (This code doesn't compile.)

#include <cstdio>

struct BostonCorbett {
    virtual void shoot() final /*1*/ {
        printf("What a God we have...God avenged Abraham Lincoln");
    }
};

struct BostonCorbettJunior : BostonCorbett {
    void shoot() override /*2*/ { } // Bang! shoot is final.
};

int main() {
    BostonCorbettJunior junior;
}
