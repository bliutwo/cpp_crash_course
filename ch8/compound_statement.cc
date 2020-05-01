#include <cstdio>

struct Tracer {
    Tracer(const char* name) : name{ name } {
        printf("%s constructed.\n", name);
    }
    ~Tracer() {
        printf("%s destructed.\n", name);
    }
private:
    const char* const name;
};

int main() {
    Tracer main{ "main" }; // 1
    {
        printf("Block a\n"); // 2
        Tracer a1{ "a1" }; // 3
        Tracer a2{ "a2" }; // 4
    }
    {
        printf("Block b\n"); // 5
        Tracer b1{ "b1" }; // 6
        Tracer b2{ "b2" }; // 7
    }
}
