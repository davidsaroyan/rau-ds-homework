#include <iostream>
#include <string>
#include <cassert>

template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

void test_mySwap() {
    int x = 10;
    int y = 20;
    mySwap(x, y);
    assert(x == 20);
    assert(y == 10);

    double pi = 3.14;
    double e = 2.71;
    mySwap(pi, e);
    assert(pi == 2.71);
    assert(e == 3.14);

    std::string str1 = "apple";
    std::string str2 = "banana";
    mySwap(str1, str2);
    assert(str1 == "banana");
    assert(str2 == "apple");

    std::cout << "All tests passed!\n";
}

int main() {
    test_mySwap();
    return 0;
}