#include <cstdio>

namespace BroopKidron13::Shaltanac {
    enum class Color {
        Mauve,
        Pink,
        Russet
    };
}

using String = const char[260]; // 1
using ShaltanacColor = BroopKidron13::Shaltanac::Color; // 2

int main() {
    const auto my_color{ ShaltanacColor::Russet }; // 3
    String saying { // 4
        "The other Shaltanac's joopleberry shrub is "
        "always a more mauvey shade of pinky russet.\n"
    };
    if (my_color == ShaltanacColor::Russet) {
        printf("%s", saying);
    }
}
