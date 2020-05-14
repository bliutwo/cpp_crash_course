#include <random>
#include <cstring>

int main() {
    char a[] = "abcdefghijklmnopqrstuvwxyz";
    std::random_device rd_engine{};
    std::uniform_int_distribution<int> int_d{ 0, 25 };
    char password[40];
    for (size_t i{}; i < 40; i++) 
        password[i] = a[int_d(rd_engine)];
    printf("%s\n", password);
}
