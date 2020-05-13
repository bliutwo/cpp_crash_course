#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <tuple>

struct Socialite { const char* birthname; };
struct Valet { const char* surname; };
Socialite bertie{ "Wilberforce" };
Valet reginald{ "Jeeves" };

struct Acquaintance { const char* nickname; };
Acquaintance hildebrand{ "Tuppy" };

TEST_CASE("std::tuple permits access to members with std::get") {
    using Trio = std::tuple<Socialite, Valet, Acquaintance>;
    Trio truculent_trio{ bertie, reginald, hildebrand };
    auto& bertie_ref = std::get<0>(truculent_trio);
    REQUIRE(bertie_ref.birthname == bertie.birthname);

    auto& tuppy_ref = std::get<Acquaintance>(truculent_trio);
    REQUIRE(tuppy_ref.nickname == hildebrand.nickname);
}
