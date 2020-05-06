#include <cstdio>
#include <cstdint>

struct LengthHistogram {
    LengthHistogram(int argc);
    ~LengthHistogram();
    void ingest(const char* x, int i);
    void print(int argc) const;
private:
    size_t* counts{};
};

LengthHistogram::LengthHistogram(int argc) {
    counts = new size_t[argc]{};
}

LengthHistogram::~LengthHistogram() {
    delete [] counts;
}

void LengthHistogram::ingest(const char* x, int i) {
    size_t index{};
    while (const auto c = x[index]) {
        counts[i]++;
        index++;
    }
}

void LengthHistogram::print(int argc) const {
    for (size_t index{1}; index < argc; index++) {
        printf("%d:\t", index);
        auto n_asterisks = counts[index];
        while (n_asterisks--) printf("*");
        printf("\n");
    }
}

int main(int argc, char** argv) {
    LengthHistogram hist(argc);
    for (size_t i{ 1 }; i < argc; i++) { // 1
        hist.ingest(argv[i], i); // 2
    }
    hist.print(argc); // 3
    return 0;
}
