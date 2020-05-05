// Using the constructor and assignment operator of function

#include <cstdio>
#include <functional>

void static_func() { // 1
    printf("A static function.\n");
}

int main() {
    std::function<void()> func { [] { printf("A lambda.\n"); } }; // 2
    func(); // 3
    func = static_func; // 4
    func(); // 5
    return 0;
}
