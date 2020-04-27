#include <stdexcept>
#include <cstdio>

struct Groucho {
    void forget(int x) {
        if (x == OxFACE) {
            throw std::runtime_error{ "I'd be glad to make an exception.\n"};
        }
        printf("Forgot Ox%x\n", x);
    }
};


