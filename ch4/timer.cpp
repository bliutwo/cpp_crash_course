#include <cstdio>
#include <ctime>

struct TimerClass {
    TimerClass() {
        timestamp = time(0);
        printf("Time: %s", ctime(&timestamp));
    }
    ~TimerClass() {
        double seconds = difftime(time(0), timestamp);
        // Goal: Get correct format specifier for double
        // Link: https://stackoverflow.com/questions/4264127/correct-format-specifier-for-double-in-printf
        printf("Age of timer: %f", seconds);
    }
private:
    time_t timestamp;
};

int main() {
    TimerClass t = TimerClass();
    return 0;
}
