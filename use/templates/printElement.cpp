#include <iostream>
#include <string>

template <typename T>
void printElement(T value) {
    std::cout << value << "\n";
}

void test_printElement() {
    int my_int = 42;
    double my_double = 3.14;
    std::string my_string = "Hello Picsart Academy";

    printElement(my_int);
    printElement(my_double);
    printElement(my_string);
}

int main() {
    test_printElement();
    return 0;
}