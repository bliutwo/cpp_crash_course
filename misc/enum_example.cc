#include <iostream>
using namespace std;

// Basically enum is declaring a type
// But a variable of the type declared by enum can only take on the values
// listed inbetween the brackets.
enum direction { East, West, North, South };

int main() {
    direction dir = South;
    // The following line will output 3 because South is the 3rd (0-indexing)
    // element between the brackets of enum direction
    cout << dir << endl;
    return 0;
}
