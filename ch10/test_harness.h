#include <exception>
#include <cstdio>

void run_test(void(*unit_test)(), const char* name) {
    try {
        unit_test(); // 1
        printf("[+] Test %s successful.\n", name); // 2
    } catch (const std::exception& e) {
        printf("[-] Test failure in %s. %s.\n", name, e.what()); // 3
    }
}
