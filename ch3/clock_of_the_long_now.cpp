#include <cstdio>

class ClockOfTheLongNow {
private:
    int year;
public:
    ClockOfTheLongNow(int year_in) {
        if(!set_year(year_in)) {
            year = 2019;
        }
    }
    ClockOfTheLongNow() {
        year = 2019;
    }
    void add_year() {
        year++;
    }
    bool set_year(int year) {
        if (year < 2019) return false;
        this->year = year;
        return true;
    }
    int get_year() const {
        return year;
    }
};

bool is_leap_year(const ClockOfTheLongNow& clock) {
    if (clock.get_year() % 4 > 0 ) return false;
    if (clock.get_year() % 100 > 0) return true;
    if (clock.get_year() % 400 > 0) return false;
    return true;
}


int main() {
    ClockOfTheLongNow clock;
    ClockOfTheLongNow* clock_ptr = &clock;
    clock_ptr->set_year(2020);
    printf("Address of clock %p\n", clock_ptr);
    printf("Value of clock's year: %d\n", clock_ptr->get_year());
    printf("Value of clock's year: %d\n", (*clock_ptr).get_year());
    printf("%d\n", is_leap_year(clock));
    return 0;
}
