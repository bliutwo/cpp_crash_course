#include <cstdio>
#include <memory>

using FileGuard = std::unique_ptr<FILE, int(*)(FILE*)>;

void say_hello(FileGuard file) {
    fprintf(file.get(), "HELLO DAVE");
}

int main() {
    auto file = fopen("HAL9000", "w");
    if (!file) return errno;
    FileGuard file_guard{ file, fclose };
    // File open here
    say_hello(std::move(file_guard));
    // File closed here
    return 0;
}
