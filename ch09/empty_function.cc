#include <cstdio>
#include <functional>

int main() {
    std::function<void()> func; // 1
    try {
        func(); // 2
    } catch(const std::bad_function_call& e) {
        printf("Exception: %s", e.what()); // 3
    }
    printf("\n");
    return 0;
}
