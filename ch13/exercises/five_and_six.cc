#include <chrono>
#include <cstdio>
#include <random>
#include <map>

long fibonacci(int index, std::vector<long>& cache) {
    if(cache.empty())
    {
        cache.push_back(1);
        cache.push_back(1);
    } else if (index > cache.size() - 1) {
        while (cache.size() - 1 < index) {
            long sum = cache[cache.size() - 1] + cache[cache.size() - 2];
            cache.push_back(sum);
        }
    }
    return cache[index];
}

long fib_sum(size_t n) {
    long sum{};
    std::vector<long> cache;
    fibonacci(n, cache);
    for (long elem : cache) {
        sum += elem;
    }
    return sum;
}

long random() {
    static std::mt19937_64 mt_engine{ 102787 };
    static std::uniform_int_distribution<long> int_d{ 1000, 2000 };
    return int_d(mt_engine);
}

struct Stopwatch {
    Stopwatch(std::chrono::nanoseconds& result)
        : result{ result },
        start{ std::chrono::system_clock::now() } { }
    ~Stopwatch() {
        result = std::chrono::system_clock::now() - start;
    }
private:
    std::chrono::nanoseconds& result;
    const std::chrono::time_point<std::chrono::system_clock> start;
};

long cached_fib_sum(const size_t& n) {
    static std::map<long, long> cache;
    if ( cache.find(n) == cache.end() ) {
        cache[n] = fib_sum(n);
    }
    return cache[n];
}

int main() {
    size_t samples{ 1'000'000 };
    std::vector<long> cache;
    std::chrono::nanoseconds elapsed;
    {
        Stopwatch stopwatch{elapsed};
        volatile double answer;
        while(samples--) {
            //answer = fib_sum(random());
            answer = cached_fib_sum(random());
        }
    }
    printf("Elapsed: %g s.\n", elapsed.count() / 1'000'000'000.);
}
