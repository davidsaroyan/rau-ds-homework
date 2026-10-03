#include <iostream>
#include <vector>
#include <string>
#include <cassert>

template <typename T>
int linearSearch(const std::vector<T>& vec, T target) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) {
            return i;
        }
    }
    return -1;
}

void test_linearSearch() {
    std::vector<int> vec_int = {10, 20, 30, 40, 50};
    assert(linearSearch(vec_int, 30) == 2);
    assert(linearSearch(vec_int, 100) == -1);

    std::vector<double> vec_double = {1.1, 2.2, 3.3, 4.4};
    assert(linearSearch(vec_double, 3.3) == 2);
    assert(linearSearch(vec_double, 5.5) == -1);

    std::vector<std::string> vec_string = {"apple", "banana", "cherry"};
    std::string target_found = "cherry";
    std::string target_not_found = "mango";
    
    assert(linearSearch(vec_string, target_found) == 2);
    assert(linearSearch(vec_string, target_not_found) == -1);

    std::cout << "All tests passed!\n";
}

int main() {
    test_linearSearch();
    return 0;
}