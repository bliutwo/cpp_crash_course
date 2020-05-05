#include <cstdio>
#include <cstdint>

struct LengthHistogram {
    LengthHistogram();
    ~LengthHistogram();
    void ingest(const char* x);
    void print() const;
private:
    size_t* counts{};
};

LengthHistogram::LengthHistogram(int argc) {
    counts = new size_t[argc];
}

LengthHistogram::~LengthHistogram() {
    delete [] counts;
}

void LengthHistogram::ingest(const char* x, int i) {
    size_t index{};
    while (const auto c = x[index]) {
        // TODO: here
        index++;
    }
}

void LengthHistogram::print() const {
    for (size_t index{}; index <= pos_Z; index++) {
        printf("%c: ", index);
        auto n_asterisks = counts[index - pos_A];
        while (n_asterisks--) printf("*");
        printf("\n");
    }
}

int main(int argc, char** argv) {
    LengthHistogram hist(argc);
    for (size_t i{ 1 }; i < argc; i++) { // 1
        hist.ingest(argv[i], i); // 2
    }
    hist.print(); // 3
    return 0;
}
