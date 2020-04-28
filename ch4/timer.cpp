#include <cstdio>
#include <ctime>
#include <cstring>

struct TimerClass {
    TimerClass(const char* name) {
        timestamp = time(0);
        this->name = new char[strlen(name)];
        strncpy(this->name, name, strlen(name));
    }
    
    TimerClass(const TimerClass& other) {
        timestamp = other.timestamp;
    }

    TimerClass& operator=(const TimerClass& other) {
        if (this == &other) return *this;
        timestamp = other.timestamp;
        return *this;
    }

    TimerClass(TimerClass&& other) noexcept {
        timestamp = other.timestamp;
        // Potential problem here because I don't know how to "zero out"
        // the `other` TimerClass, since it's in a "moved-from" state
        other.timestamp = 0;
    }

    TimerClass& operator=(TimerClass&& other) noexcept {
        if (this == &other) return *this;
        timestamp = other.timestamp;
        // Same problem with this line
        other.timestamp = 0;
        return *this;
    }

    void get_time() {
        printf("Time: %s", ctime(&timestamp));
    }

    ~TimerClass() {
        double seconds = difftime(time(0), timestamp);
        // Goal: Get correct format specifier for double
        // Link: https://stackoverflow.com/questions/4264127/correct-format-specifier-for-double-in-printf
        printf("Age of timer %s: %f\n", name, seconds);
    }
private:
    time_t timestamp;
    char* name;
};

int main() {
    TimerClass t = TimerClass("t");
    t.get_time();
    TimerClass s = t;
    s.get_time();
    return 0;
}
