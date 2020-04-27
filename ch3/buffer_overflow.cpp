#include <cstdio>

char read_from(char* s, int n, int i) {
    if (i >= n || i < 0) {
        printf("Invalid read.\n");
        return '\0';
    } else {
        return s[i];
    }
}

void write_to(char* s, int n, int i, char c) {
    if (i >= n || i < 0) {
        printf("Invalid write.\n");
    } else {
        s[i] = c;
    }
}

int main() {
    char lower[] = "abc?e";
    char upper[] = "ABC?E";
    char* upper_ptr = upper;        // Equivalent: &upper[0]

    printf("%zu\n", sizeof(lower));

    // lower[3] = 'd';                 // lower now contains a b c d e \0
    // upper_ptr[3] = 'D';             // upper now contains A B C D E \0
    
    write_to(lower, sizeof(lower), 3, 'd');
    write_to(upper, sizeof(upper), 3, 'D');

    // char letter_d = lower[3];       // letter_d equals 'd'
    // char letter_D = upper_ptr[3];   // letter_D equals 'D'
    
    char letter_d = read_from(lower, sizeof(lower), 3);
    char letter_D = read_from(upper, sizeof(upper), 3);

    printf("lower: %s\nupper: %s\n", lower, upper);

    // lower[7] = 'g';                 // Super bad. You must never do this.
    write_to(lower, sizeof(lower), 7, 'g');
    write_to(upper, sizeof(upper), -2948357, 'f');
}
