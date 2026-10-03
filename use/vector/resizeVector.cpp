#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
void resizeVector(std::vector<T>& vec, size_t new_size, T default_value){
    std::cout << "Before: ";
    for(size_t i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";

    vec.resize(new_size, default_value);

    std::cout << "After: ";
    for(size_t i = 0; i < vec.size(); ++i){
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

void test_resizeVector(){
    std::vector<int> vec1 = {1, 2, 3};
    resizeVector(vec1, 5, 9);
    std::vector<int> expected1 = {1, 2, 3, 9, 9};
    assert(vec1 == expected1);
    assert(vec1.size() == 5);

    std::vector<int> vec2 = {1, 2, 3, 4, 5};
    resizeVector(vec2, 2, 0);
    std::vector<int> expected2 = {1, 2};
    assert(vec2 == expected2);
    assert(vec2.size() == 2);

    std::cout << "All tests passed!\n";
}

int main(){
    test_resizeVector();
    return 0;
}