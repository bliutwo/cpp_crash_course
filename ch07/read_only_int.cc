struct ReadOnlyInt {
    ReadOnlyInt(int val) : val{ val } { }
    explicit operator int() const {
        return val;
    }
private:
    const int val;
};

int main() {
    ReadOnlyInt the_answer{ 42 };
    auto ten_answers = static_cast<int>(the_answer) * 10; // int with value 420
    return 0;
}
