#include <iostream>
#include <string>
#include <cassert>

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(T1 f, T2 s) {
        first = f;
        second = s;
    }

    T1 getFirst() const {
        return first;
    }

    T2 getSecond() const {
        return second;
    }

    void print() const {
        std::cout << "[" << first << ", " << second << "]\n";
    }
};

void test_Pair() {
    Pair<int, double> p1(5, 3.14);
    assert(p1.getFirst() == 5);
    assert(p1.getSecond() == 3.14);
    
    std::cout << "Printing p1: ";
    p1.print();

    Pair<std::string, int> p2("Age", 20);
    assert(p2.getFirst() == "Age");
    assert(p2.getSecond() == 20);
    
    std::cout << "Printing p2: ";
    p2.print();

    Pair<char, std::string> p3('A', "Excellent");
    assert(p3.getFirst() == 'A');
    assert(p3.getSecond() == "Excellent");
    
    std::cout << "Printing p3: ";
    p3.print();

    std::cout << "All tests passed!\n";
}

int main() {
    test_Pair();
    return 0;
}