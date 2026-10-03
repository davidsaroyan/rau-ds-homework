#include <iostream>
#include <vector>
#include <cassert>

int findSubsequence(const std::vector<int>& main_vec, const std::vector<int>& sub_vec) {
    if (sub_vec.empty()) {
        return 0;
    }
    
    if (main_vec.size() < sub_vec.size()) {
        return -1;
    }

    for (size_t i = 0; i <= main_vec.size() - sub_vec.size(); ++i) {
        bool match = true;
        
        for (size_t j = 0; j < sub_vec.size(); ++j) {
            if (main_vec[i + j] != sub_vec[j]) {
                match = false;
                break;
            }
        }
        
        if (match) {
            return i;
        }
    }

    return -1;
}

void test_findSubsequence() {
    std::vector<int> main_vec = {1, 2, 3, 4, 5, 6};
    std::vector<int> sub_vec = {3, 4, 5};
    assert(findSubsequence(main_vec, sub_vec) == 2);

    std::vector<int> sub_vec_not_found = {7, 8};
    assert(findSubsequence(main_vec, sub_vec_not_found) == -1);

    std::vector<int> main_vec_short = {1, 2};
    std::vector<int> sub_vec_long = {1, 2, 3};
    assert(findSubsequence(main_vec_short, sub_vec_long) == -1);

    std::vector<int> empty_sub_vec = {};
    assert(findSubsequence(main_vec, empty_sub_vec) == 0);

    std::vector<int> duplicate_patterns = {1, 2, 1, 2, 3};
    std::vector<int> sub_pattern = {1, 2, 3};
    assert(findSubsequence(duplicate_patterns, sub_pattern) == 2);

    std::cout << "All tests passed!\n";
}

int main() {
    test_findSubsequence();
    return 0;
}