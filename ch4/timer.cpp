#include <cstdio>
#include <ctime>
#include <chrono>
#include <iostream>
#include <typeinfo>

// struct TimerClass {
//     TimerClass() {
//     }
// private:
//     time_t timestamp;
// };

int main() {
    auto start = std::chrono::system_clock::now();
    std::cout << "start is: " << typeid(start).name() << std::endl;
    return 0;
}
