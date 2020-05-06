#include <cstdio>

namespace BroopKidron13::Shaltanac {
    enum class Color {
        Mauve,
        Pink,
        Russet
    };

    struct JoopleBerryShrub {
        const char* name;
        Color shade;
    };

    bool is_more_mauvey(const JoopleBerryShrub& shrub) {
        return shrub.shade == Color::Mauve;
    }
}

using namespace BroopKidron13::Shaltanac; // 1

int main() {
    const JoopleBerryShrub /*2*/ yours {
        "The other Shaltanac",
        Color::Mauve // 3
    };

    if (is_more_mauvey(yours) /*4*/ ) {
        printf("The other Shaltanac's joopleberry shrub is always "
               "a more mauvey shade of pinky russet.\n");
    }
}
