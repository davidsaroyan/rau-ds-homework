#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> mergeSortedVectors(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    std::vector<int> merged;
    size_t i = 0;
    size_t j = 0;

    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] < vec2[j]) {
            merged.push_back(vec1[i]);
            ++i;
        } else {
            merged.push_back(vec2[j]);
            ++j;
        }
    }

    while (i < vec1.size()) {
        merged.push_back(vec1[i]);
        ++i;
    }

    while (j < vec2.size()) {
        merged.push_back(vec2[j]);
        ++j;
    }

    return merged;
}

void test_mergeSortedVectors() {
    std::vector<int> vec1 = {1, 3, 5, 7};
    std::vector<int> vec2 = {2, 4, 6, 8, 9};
    std::vector<int> merged = mergeSortedVectors(vec1, vec2);
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(merged == expected);

    std::vector<int> empty1 = {};
    std::vector<int> empty2 = {1, 2, 3};
    assert(mergeSortedVectors(empty1, empty2) == empty2);

    std::vector<int> both_empty1 = {};
    std::vector<int> both_empty2 = {};
    std::vector<int> expected_empty = {};
    assert(mergeSortedVectors(both_empty1, both_empty2) == expected_empty);

    std::vector<int> duplicates1 = {1, 2, 2};
    std::vector<int> duplicates2 = {2, 3, 4};
    std::vector<int> expected_duplicates = {1, 2, 2, 2, 3, 4};
    assert(mergeSortedVectors(duplicates1, duplicates2) == expected_duplicates);

    std::cout << "All tests passed!\n";
}

int main() {
    test_mergeSortedVectors();
    return 0;
}