#include <cstdio>

template<typename T>
T square(T value) {
    return value * value;
}

int main() {
    //char my_char{ 'Q' };
    //auto result = square(&my_char);
    
    int a = 2;
    int result = square(a);

    printf("result: %d\n", result);

    return 0;
}
