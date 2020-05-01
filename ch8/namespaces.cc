#include <cstdio>

namespace BroopKidron13::Shaltanac { // 1
    enum class Color { // 2
        Mauve,
        Pink,
        Russet
    };
}

int main() {
    using BroopKidron13::Shaltanac::Color;
    // const auto shaltanac_grass { BroopKidron13::Shaltanac::Color::Russet /* 3 */};
    const auto shaltanac_grass = Color::Russet;
    // if (shaltanac_grass == BroopKidron13::Shaltanac::Color::Russet) {
    if (shaltanac_grass == Color::Russet) {
        printf("The other Shaltanac's joopleberry shrub is always "
               "a more mauvey shade of pinky russet.\n");
    }
}
