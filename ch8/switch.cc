#include <cstdio>

enum class Color { // 1
    Mauve,
    Pink,
    Russet
};

struct Result { // 2
    const char* name;
    Color color;
};

Result observe_shrub(const char* name) { // 3
    return Result{ name, Color::Russet };
}

int main() {
    const char* description;
    switch (const auto result /*4*/= observe_shrub("Zaphod"); result.color /*5*/) {
    case Color::Mauve: {
        description = "mauvey shade of pinky russet";
        break;
    } case Color::Pink: {
        description = "pinky shade of mauvey russet";
        break;
    } case Color::Russet: {
        description = "russety shade of pinky mauve";
        break;
    } default: {
        description = "enigmatic shade of whitish black";
    }}
    printf("The other Shaltanac's joopleberry shrub is "
           "always a more %s.\n", description); // 6
    return 0;
}
