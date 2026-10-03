#include <iostream>
#include <string>

template <typename T>
void printValue(T value) {
    std::cout << value << "\n";
}

template <>
void printValue<bool>(bool value) {
    if (value) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
}

template <>
void printValue<const char*>(const char* value) {
    std::cout << "[\"" << value << "\"]\n";
}

template <>
void printValue<char*>(char* value) {
    std::cout << "[\"" << value << "\"]\n";
}

void test_printValue() {
    int my_int = 42;
    printValue(my_int);

    double my_double = 3.14;
    printValue(my_double);

    bool is_valid = true;
    bool is_empty = false;
    printValue(is_valid);
    printValue(is_empty);

    printValue("Picsart Academy");

    char mutable_string[] = "C++17";
    printValue(static_cast<char*>(mutable_string));

    std::cout << "All tests passed!\n";
}

int main() {
    test_printValue();
    return 0;
}