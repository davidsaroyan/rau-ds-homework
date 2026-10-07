#include <iostream>
#include <string>
#include <cassert>

template <typename T, int N>
class FixedArray {
private:
    T data[N];

public:
    void set(int index, T value) {
        data[index] = value;
    }

    T get(int index) const {
        return data[index];
    }

    int size() const {
        return N;
    }
};

void test_FixedArray() {
    FixedArray<int, 5> intArray;
    intArray.set(0, 10);
    intArray.set(2, 30);
    intArray.set(4, 50);
    
    assert(intArray.get(0) == 10);
    assert(intArray.get(2) == 30);
    assert(intArray.get(4) == 50);
    assert(intArray.size() == 5);

    FixedArray<double, 3> doubleArray;
    doubleArray.set(0, 1.1);
    doubleArray.set(1, 2.2);
    doubleArray.set(2, 3.3);
    
    assert(doubleArray.get(1) == 2.2);
    assert(doubleArray.size() == 3);

    FixedArray<std::string, 2> stringArray;
    stringArray.set(0, "Picsart");
    stringArray.set(1, "Academy");
    
    assert(stringArray.get(0) == "Picsart");
    assert(stringArray.get(1) == "Academy");
    assert(stringArray.size() == 2);

    std::cout << "All tests passed!\n";
}

int main() {
    test_FixedArray();
    return 0;
}