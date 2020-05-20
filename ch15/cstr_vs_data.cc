#include <string>
#include <cstdio>

int main() {
    std::string word("pulchritudinous");
    printf("c_str: %s at %p\n", word.c_str(), word.c_str());
    printf("data:  %s at %p\n", word.data(), word.data());
}
