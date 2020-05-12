#include <memory>

std::shared_ptr<int> sh_ptr {
    new int{ 10 },
    [](int* x) { delete x; },
    std::allocator<int>{}
};

int main() {
    // std::shared_ptr<int> my_ptr{ new int{ 808 } };
    auto my_ptr = std::make_shared<int>(808);
    return 0;
}
