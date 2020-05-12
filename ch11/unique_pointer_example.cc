#include <memory>

int main() {
    std::unique_ptr<int> my_ptr{ new int{ 808 } };
    auto my_ptr = make_unique<int>(808);
    return 0;
}
