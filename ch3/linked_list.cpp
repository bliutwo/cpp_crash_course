#include <cstdio>

struct Element {
    Element* next{};
    Element* prev{};
    void insert_after(Element* new_element) {
        new_element->next = this->next;
        this->next = new_element;
    }
    void insert_before(Element* new_element) {
        new_element->next = this;
        this->prev = new_element;
    }
    char prefix[2];
    short operating_number;
};

int main() {
    Element trooper1, trooper2, trooper3;
    trooper1.prefix[0] = 'T';
    trooper1.prefix[1] = 'K';
    trooper1.operating_number = 421;
    // trooper1.insert_after(&trooper2);
    trooper2.prefix[0] = 'F';
    trooper2.prefix[1] = 'N';
    trooper2.operating_number = 2187;
    // trooper2.insert_after(&trooper3);
    trooper2.insert_before(&trooper1);
    trooper3.prefix[0] = 'L';
    trooper3.prefix[1] = 'S';
    trooper3.operating_number = 005;
    trooper3.insert_before(&trooper2);

    for (Element *cursor = &trooper1; cursor; cursor = cursor->next) {
        printf("stormtrooper %c%c-%d\n",
                cursor->prefix[0],
                cursor->prefix[1],
                cursor->operating_number);
        if (cursor->prev) {
            printf("previous stormtrooper: %c%c-%d\n",
                    cursor->prev->prefix[0],
                    cursor->prev->prefix[1],
                    cursor->prev->operating_number);
        }
        if (cursor->next) {
            printf("next stormtrooper: %c%c-%d\n",
                    cursor->next->prefix[0],
                    cursor->next->prefix[1],
                    cursor->next->operating_number);
        }
    }
    for (Element *cursor = &trooper1; cursor; cursor = cursor->next) {
        printf("stormtrooper %c%c-%d\n",
                cursor->prefix[0],
                cursor->prefix[1],
                cursor->operating_number);
    }
    for (Element *cursor = &trooper3; cursor; cursor = cursor->prev) {
        printf("stormtrooper %c%c-%d\n",
                cursor->prefix[0],
                cursor->prefix[1],
                cursor->operating_number);
    }
}

