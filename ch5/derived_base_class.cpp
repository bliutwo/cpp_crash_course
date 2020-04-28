#include <cstdio>

struct BaseClass {
    int the_answer() const { return 42; }
    const char* member = "gold";
private:
    const char* holistic_detective = "Dirk Gently";
};

struct DerivedClass : BaseClass {};
void are_belong_to_us(BaseClass& base) {}
void all_about_that(DerivedClass& derived) {}

int main1() {
    BaseClass base;
    // all_about_that(base); // No! Trouble!
    return 0;
}

int main2() {
    DerivedClass derived;
    are_belong_to_us(derived);
    return 0;
}

int main() {
    DerivedClass x;
    printf("The answer is %d\n", x.the_answer());
    printf("%s member\n", x.member);
    // This line doesn't compile
    // printf("%s's Holistic Detective Agency\n", x.holistic_detective);
    return 0;
}
