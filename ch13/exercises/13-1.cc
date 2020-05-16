#include <cstdio>
#include <vector>

int fibonacci(int index, std::vector<int>& cache) {
    if(cache.empty())
    {
        cache.push_back(1);
        cache.push_back(1);
    } else if (index > cache.size() - 1) {
        while (cache.size() - 1 < index) {
            int sum = cache[cache.size() - 1] + cache[cache.size() - 2];
            cache.push_back(sum);
        }
    }
    return cache[index];
}

int main() {
    std::vector<unsigned long> v;
    printf("Capacity of v: %lu\n", v.capacity()); 
    v.reserve(10);

    std::vector<int> cache;
    for (int i{}; i < 20; i++)
    {
        int element = fibonacci(i, cache);
        v.push_back(element);
    }
    printf("Capacity of v: %lu\n", v.capacity()); 
    printf("Number of elems in v: %lu\n", v.size());

    // The capacity matches the number of elements in v.
    // Why is this? v must have doubled in capacity once we started adding
    // more elements that it had capacity for (i.e. after adding 11th elem).
    
    for (int elem : v) {
        printf("elem: %d\n", elem);
    }

    return 0;
}
