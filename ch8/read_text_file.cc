#include <cstdio>

struct TextFile { // 1
    bool success;
    const char* contents;
    size_t n_bytes;
};

TextFile read_text_file(const char* path) { // 2
    const static char contents[]{ "Sometimes the goat is you." };
    return TextFile{
        true,
        contents,
        sizeof(contents)
    };
}

int main() {
    const auto [success, contents, length] /*3*/= read_text_file("REAMDE.txt"); // 4
    if (success /*5*/) {
        printf("Read %zd bytes: %s\n", length /*6*/, contents /*7*/);
    } else {
        printf("Failed to open REAMDE.txt.");
    }
}
