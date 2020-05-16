// TODO: Exercise 13-7

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Matrix.h"

TEST_CASE("Matrix and std::initializer_list") {
    Matrix<int> mat {
        1,  2,  3,  4,
        5,  0,  7,  8,
        9, 10, 11, 12,
       13, 14, 15, 16
    };
    REQUIRE(mat.dim == 4);
    mat.at(1, 1) = 6;
    REQUIRE(mat.at(1, 1) == 6);
    REQUIRE(mat.at(0, 2) == 3);
}
