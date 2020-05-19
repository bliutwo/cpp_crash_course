#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <string>

TEST_CASE("std::string supports constructing") {
    SECTION("empty strings") {
        std::string cheese;
        REQUIRE(cheese.empty());
    }
    SECTION("repeated characters") {
        std::string roadside_assistance(3, 'A');
        REQUIRE(roadside_assistance == "AAA");
    }
}

TEST_CASE("std::string supports constructing substrings ") {
    auto word = "gobbledygook";
    REQUIRE(std::string(word) == "gobbledygook");
    REQUIRE(std::string(word, 6) == "gobble");
}

TEST_CASE("std::string supports") {
    std::string word("catawampus");
    SECTION("copy constructing") {
        REQUIRE(std::string(word) == "catawampus");
    }
    SECTION("move constructing") {
        REQUIRE(std::string(move(word)) == "catawampus");
    }
    SECTION("constructing from substrings") {
        REQUIRE(std::string(word, 0, 3) == "cat");
        REQUIRE(std::string(word, 4) == "wampus");
    }
}


