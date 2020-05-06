#include <cstdio>

template<typename X, typename Y, typename Z>
struct MyTemplateClass {
    X foo(Y&);
private:
    Z* member;
};

//X my_template_function(Y& arg1, const Z* arg2) {
//}

void carbon_thaw(const int& encased_solo) {
    // encased_solo++; // Compiler error; modifying const
    auto& hibernation_sick_solo = const_cast<int&>(encased_solo);
    hibernation_sick_solo++;
}

int main() {
    return 0;
}
