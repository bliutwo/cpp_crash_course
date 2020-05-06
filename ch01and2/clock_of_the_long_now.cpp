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
    bool set_year(int new_year) {
        if (new_year < 2019) return false;
        year = new_year;
        return true;
    }
    int get_year() {
        return year;
    }
};


int main() {
    ClockOfTheLongNow clock;
    printf("Default year: %d\n", clock.get_year());
    ClockOfTheLongNow clock2{ 2020 };
    printf("Year: %d\n", clock2.get_year());
    return 0;
}
