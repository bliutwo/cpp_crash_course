#include <cstdio>
#include <ctime>

struct TimerClass {
    TimerClass() {
        timestamp = time(0);
    }
private:
    time_t timestamp;
};

int main() {
    TimerClass t = TimerClass();
    return 0;
}
