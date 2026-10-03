#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> createVectorFromInput() {
    std::vector<int> vec;
    int number;
    while (true) {
        std::cin >> number;
        if (number == 0) {
            break;
        }
        vec.push_back(number);
    }

    std::cout << "size: " << vec.size() << "\n";
    std::cout << "Elements: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";

    return vec;
}
void test_createVectorFromInput() {
    std::cout << "Testing createVectorFromInput\n";
    std::cout << "enter the numbers: 7 8 9 0\n";

    std::vector<int> result = createVectorFromInput();
    std::vector<int> expected = {7, 8, 9};
    assert(result == expected);
    assert(result.size() == 3);

    std::cout << "All Test passed\n";
}

int main() {
    test_createVectorFromInput();
    return 0;
}