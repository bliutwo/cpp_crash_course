struct DeadMenOfDunharrow {
    DeadMenOfDunharrow(const char* m="")
        : message{ m } {
        oaths_to_fulfill++;
    }
    ~DeadMenOfDunharrow() {
        oaths_to_fulfill--;
    }
    const char* message;
    static int oaths_to_fulfill;
};
