#include <cstdio>

struct TextFile {
    bool success;
    const char* contents;
    size_t n_bytes;
};

TextFile read_text_file(const char* path) {
    const static char contents[]{ "Sometimes the goat is you." };
    return TextFile{
        true,
        contents,
        sizeof(contents)
    };
}

int main() {
    if (const auto [success, txt, len] /*1*/ = read_text_file("REAMDE.txt"); success /*2*/)
    {
        printf("Read %d bytes: %s\n", len, txt); // 3
    } else {
        printf("Failed to open REAMDE.txt."); // 4
    }
    return 0;
}
