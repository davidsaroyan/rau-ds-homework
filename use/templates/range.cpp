#include <iostream>
#include <cassert>

template <typename T>
class Range {
private:
    T start;
    T end;

public:
    Range(T s, T e) {
        start = s;
        end = e;
    }

    bool contains(const T& value) const {
        return value >= start && value <= end;
    }

    auto length() const {
        return end - start;
    }

    void print() const {
        std::cout << "[" << start << ", " << end << "]\n";
    }
};

void test_Range() {
    Range<int> intRange(3, 10);
    assert(intRange.contains(5) == true);
    assert(intRange.contains(1) == false);
    assert(intRange.contains(10) == true);
    assert(intRange.length() == 7);
    
    std::cout << "Integer range: ";
    intRange.print();

    Range<double> doubleRange(1.5, 5.5);
    assert(doubleRange.contains(3.14) == true);
    assert(doubleRange.contains(6.0) == false);
    assert(doubleRange.length() == 4.0);
    
    std::cout << "Double range: ";
    doubleRange.print();

    Range<char> charRange('a', 'f');
    assert(charRange.contains('c') == true);
    assert(charRange.contains('z') == false);
    assert(charRange.length() == 5); 
    
    std::cout << "Char range: ";
    charRange.print();

    std::cout << "All tests passed!\n";
}

int main() {
    test_Range();
    return 0;
}