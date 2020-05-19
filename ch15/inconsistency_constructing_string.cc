#include <iostream>
#include <string>

int main() {
    char cstyle[] = "01234567";
    std::string std = "01234567";
    std::cout << std::string(cstyle, 4) << std::endl;
    std::cout << std::string(std, 4) << std::endl;
    return 0;
}
