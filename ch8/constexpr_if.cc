#include <cstdio>
#include <stdexcept>
#include <type_traits>

template <typename T>
auto value_of(T x /* 1 */) {
    if constexpr (std::is_pointer<T>::value) { // 2
        if (!x) throw std::runtime_error{ "Null pointer dereference." }; // 3
        return *x; // 4
    } else {
        return x; // 5
    }
}

int main() {
    unsigned long level{ 8998 };
    auto level_ptr = &level;
    auto &level_ref = level;
    printf("Power level = %lu\n", value_of(level_ptr)); // 6
    ++*level_ptr;
    printf("Power level = %lu\n", value_of(level_ref)); // 7
    ++level_ref;
    printf("It's over %lu!\n", value_of(level++)); // 8
    try {
        level_ptr = nullptr;
        value_of(level_ptr);
    } catch (const std::exception& e) {
        printf("Exception: %s\n", e.what()); // 9
    }
}
