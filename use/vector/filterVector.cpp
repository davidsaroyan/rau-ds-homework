#include <iostream>
#include <vector>
#include <cassert>

template <typename T, typename Predicate>
std::vector<T> filterVector(const std::vector<T>& vec, Predicate pred) {
    std::vector<T> result;
    
    for (size_t i = 0; i < vec.size(); ++i) {
        if (pred(vec[i])) {
            result.push_back(vec[i]);
        }
    }
    
    return result;
}

bool isEven(int x) { 
    return x % 2 == 0; 
}

bool isGreaterThanTen(int x) {
    return x > 10;
}

void test_filterVector() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::vector<int> expected_even = {2, 4, 6};
    assert(filterVector(vec, isEven) == expected_even);

    std::vector<int> all_odd = {1, 3, 5, 7};
    std::vector<int> expected_empty = {};
    assert(filterVector(all_odd, isEven) == expected_empty);

    std::vector<int> empty_vec = {};
    assert(filterVector(empty_vec, isEven) == expected_empty);

    std::vector<int> mixed_nums = {5, 12, 8, 15, 3};
    std::vector<int> expected_greater = {12, 15};
    assert(filterVector(mixed_nums, isGreaterThanTen) == expected_greater);

    std::cout << "All tests passed!\n";
}

int main() {
    test_filterVector();
    return 0;
}