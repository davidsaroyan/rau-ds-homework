#include <iostream>
#include <vector>
#include <cassert>

std::vector<std::vector<int>> groupAdjacent(const std::vector<int>& vec) {
    std::vector<std::vector<int>> result;
    
    if (vec.empty()) {
        return result;
    }

    std::vector<int> current_group;
    current_group.push_back(vec[0]);

    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] == vec[i - 1]) {
            current_group.push_back(vec[i]);
        } else {
            result.push_back(current_group);
            current_group.clear();
            current_group.push_back(vec[i]);
        }
    }
    
    result.push_back(current_group);
    
    return result;
}

void test_groupAdjacent() {
    std::vector<int> vec = {1, 1, 2, 2, 2, 3, 1, 1};
    std::vector<std::vector<int>> expected = {{1, 1}, {2, 2, 2}, {3}, {1, 1}};
    assert(groupAdjacent(vec) == expected);

    std::vector<int> vec2 = {5, 5, 5};
    std::vector<std::vector<int>> expected2 = {{5, 5, 5}};
    assert(groupAdjacent(vec2) == expected2);

    std::vector<int> vec3 = {1, 2, 3};
    std::vector<std::vector<int>> expected3 = {{1}, {2}, {3}};
    assert(groupAdjacent(vec3) == expected3);

    std::vector<int> empty_vec = {};
    std::vector<std::vector<int>> expected_empty = {};
    assert(groupAdjacent(empty_vec) == expected_empty);

    std::cout << "All tests passed!\n";
}

int main() {
    test_groupAdjacent();
    return 0;
}