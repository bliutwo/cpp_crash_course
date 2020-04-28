#include <stdexcept>
#include <cstdio>
#include <cstring>

struct SimpleString {
    SimpleString(size_t max_size)
        : max_size { max_size },
          length{} {
        if (max_size == 0) {
            throw std::runtime_error{ "Max size must be at least 1." };
        }
        buffer = new char[max_size];
        buffer[0] = 0;
    }

    SimpleString(const SimpleString& other)
        : max_size{ other.max_size },
          buffer{ new char[other.max_size] },
          length{ other.length } {
          std::strncpy(buffer, other.buffer, max_size);
    }

    SimpleString& operator=(const SimpleString& other) {
        if (this == &other) return *this;
        const auto new_buffer = new char[other.max_size];
        delete[] buffer;
        buffer = new_buffer;
        length = other.length;
        max_size = other.max_size;
        std::strncpy(buffer, other.buffer, max_size);
        return *this;
    }

    SimpleString& operator=(SimpleString&& other) noexcept {
        if (this == &other) return *this;
        delete[] buffer;
        buffer = other.buffer;
        length = other.length;
        max_size = other.max_size;
        other.buffer = nullptr;
        other.length = 0;
        other.max_size = 0;
        return *this;
    }

    SimpleString(SimpleString&& other) noexcept
        : max_size{ other.max_size },
        buffer(other.buffer),
        length(other.length) {
        other.length = 0;
        other.buffer = nullptr;
        other.max_size = 0;
    }

    ~SimpleString() {
        delete[] buffer;
    }

    void print(const char* tag) const {
        printf("%s: %s", tag, buffer);
    }

    bool append_line(const char* x) {
        const auto x_len = strlen(x);
        if (x_len + length + 2 > max_size) return false;
        std::strncpy(buffer + length, x, max_size - length);
        length += x_len;
        buffer[length++] = '\n';
        buffer[length] = 0;
        return true;
    }

private:
    size_t max_size;
    char* buffer;
    size_t length;
};

struct SimpleStringOwner {
    SimpleStringOwner(const char* x)
        : string { 10 } {
        if (!string.append_line(x)) {
            throw std::runtime_error{ "Not enough memory!" };
        }
        string.print("Constructed");
    }

    SimpleStringOwner(const SimpleString& my_string): string { my_string } { }

    ~SimpleStringOwner() {
        string.print("About to destroy");
    }

private:
    SimpleString string;
};

void fn_c() {
    SimpleStringOwner c{ "cccccccccc" };
}

void fn_b() {
    SimpleStringOwner b{ "b" };
    fn_c();
}

int main2() {
    SimpleString string{ 115 };
    string.append_line("Starbuck, whaddya hear?");
    string.append_line("Nothin' but the rain.");
    string.print("A: ");
    string.append_line("Grab your gun and bring the cat in.");
    string.append_line("Aye-aye sir, coming home.");
    string.print("B: ");
    if(!string.append_line("Galactica!")) {
        printf("String was not big enough to append another message.\n");
    }
    return 0;
}

int main1() {
    SimpleStringOwner x{ "x" };
    printf("x is alive\n");
    return 0;
}

int main0() {
    try {
        SimpleStringOwner a{ "a" };
        fn_b();
        SimpleStringOwner d{ "d" };
    } catch(const std::exception& e) {
        printf("Exception: %s\n", e.what());
    }
    return 0;
}

int main3() {
    SimpleString a{ 50 };
    a.append_line("We apologize for the");
    SimpleString a_copy{ a };
    a.append_line("inconvenience.");
    a_copy.append_line("incontinence.");
    a.print("a");
    a_copy.print("a_copy");
    return 0;
}

void foo(SimpleString x) {
    x.append_line("This change is lost.");
}

void dont_do_this() {
    SimpleString a{ 50 };
    a.append_line("We apologize for the");
    SimpleString b{ 50 };
    b.append_line("Last message");
    b = a;
}

int main4() {
    SimpleString a{ 20 };
    foo(a);
    a.print("Still empty");
    return 0;
}

void own_a_string() {
    SimpleString a{ 50 };
    a.append_line("We apologize for the");
    a.append_line("inconvenience.");
    SimpleStringOwner b{ a };
}

int main() {
    SimpleString a{ 50 };
    a.append_line("We apologize for the");
    SimpleString b{ 50 };
    b.append_line("Last message");
    a.print("a");
    b.print("b");
    b = a;
    a.print("a");
    b.print("b");
    return 0;
}
