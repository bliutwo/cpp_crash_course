#include <cstdio>

void petruchio(const char* shrew) {
    printf("Fear not, sweet wench, they shall not touch thee, %s.", shrew);
    shrew[0] = "K"; // Compiler error! The shrew cannot be tamed.
}
