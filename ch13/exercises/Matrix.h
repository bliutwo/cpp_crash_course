// TODO: Exercise 13-7

#include <cmath>
#include <stdexcept>
#include <initializer_list>
#include <vector>

size_t square_root(size_t x) {
    const auto result = static_cast<size_t>(sqrt(x));
    if (result * result != x) throw std::logic_error{ "Not a perfect square." };
    return result;
}

template <typename T>
struct Matrix {
    Matrix(std::initializer_list<T> val)
        : dim{ square_root(val.size()) },
          data(dim, std::vector<T>{}) {
        auto itr = val.begin();
        for(size_t row{}; row < dim; row++) {
            data[row].assign(itr, itr+dim);
            itr += dim;
        }
    }
    T& at(size_t row, size_t col) {
        if (row >= dim || col >= dim)
            throw std::out_of_range{ "Index invalid." };
        return data[row][col];
    }
    const size_t dim;
private:
    std::vector<std::vector<T>> data;
};
