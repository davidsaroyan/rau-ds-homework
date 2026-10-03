#include <iostream>
#include <cstring>
#include <cassert>

template <typename T>
bool isEqual(const T& a, const T& b) {
    return a == b;
}

template <>
bool isEqual<const char*>(const char* const& a, const char* const& b) {
    if (!a || !b) {
        return a == b;
    }
    return std::strcmp(a, b) == 0;
}

void test_isEqual() {
    assert(isEqual(5, 5) == true);
    assert(isEqual(5, 10) == false);

    assert(isEqual(3.14, 3.14) == true);
    assert(isEqual(3.14, 2.71) == false);

    const char* str1 = "hello";
    const char* str2 = "hello";
    const char* str3 = "world";

    assert(isEqual(str1, str2) == true);
    assert(isEqual(str1, str3) == false);

    std::cout << "All tests passed!\n";
}

int main() {
    test_isEqual();
    return 0;
}