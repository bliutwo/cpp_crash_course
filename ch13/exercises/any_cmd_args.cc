// TODO: Why does this print reverse alpha order?

#include <cstdio>
#include <set>
#include <string.h>

struct alph_compare {
    bool operator()(const char* a, const char* b) const {
        return strcmp(a, b);
    }
};

int main(int argc, char* argv[]) {
    std::set<const char*, alph_compare> s;
    for (int i = 0; i < argc; i++) {
        s.insert(argv[i]);
    }
    std::set<const char*>::iterator it;
    for (it = s.begin(); it != s.end(); ++it) {
        printf("%s\n", *it);
    }
}
