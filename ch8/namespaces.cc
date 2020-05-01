#include <cstdio>

namespace BroopKidron13::Shaltanac { // 1
    enum class Color { // 2
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

using namespace BroopKidron13::Shaltanac;

int main() {
    const JoopleBerryShrub yours {
        "The other Shaltanac",
        Color::Mauve
    };

    if (is_more_mauvey(yours) /*4*/ ) {
        printf("The other Shaltanac's joopleberry shrub is always "
               "a more mauvey shade of pinky russet.\n");
    }
}
