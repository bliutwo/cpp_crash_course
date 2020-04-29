#include <cstdio>
#include <map>
#include <utility>
#include <algorithm>

// https://stackoverflow.com/a/9371137
template<typename T>
T get_key_with_max_value(std::map<T, int> m) {
    auto max_key = std::max_element(m.begin(), m.end(),
            [](const std::pair<T, int>& p1, const std::pair<T, int>& p2) {
                return p1.second < p2.second;
            });
    return max_key->first;
}

template<typename T>
T mode(const T* values, size_t length) {
    std::map<T, int> m;
    for (size_t i{}; i < length; i++) {
        T curr = values[i];
        if ( m.find(curr) == m.end() ) {
            m[curr] = 1;
        } else {
            m[curr] += 1;
        }
    }
    return get_key_with_max_value(m);
}

int main() {
    int arr[] = {1, 1, 2, 3, 4, 4, 4, 5};
    // expect 4
    printf("mode: %d\n", mode(arr, sizeof(arr) / sizeof(int)));
    return 0;
}
