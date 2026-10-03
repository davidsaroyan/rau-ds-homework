#include <iostream>
#include <vector>
#include <cassert>

int removeElementsGreaterThan(std::vector<int> &vec, int target){
    int ctr = 0;
    while (!vec.empty() && vec.back() > target) {
        vec.pop_back();
        ++ctr;
    }
    return ctr;
}

void test_removeElementsGreaterThan() {
    std::cout << "Testing removeElementsGreaterThan\n";
    //Standard case
    {
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
        int deleted = removeElementsGreaterThan(vec, 5);
        std::vector<int> expected_vec = {1, 2, 3, 4, 5};
        
        assert(deleted == 2);
        assert(vec == expected_vec);
    }

    //Empty vector
    {
        std::vector<int> vec = {};
        int deleted = removeElementsGreaterThan(vec, 0);
        std::vector<int> expected_vec = {};
        
        assert(deleted == 0);
        assert(vec == expected_vec);
    }

    //All elements are greater than target (vec becomes empty)
    {
        std::vector<int> vec = {10, 20, 30};
        int deleted = removeElementsGreaterThan(vec, 5);
        std::vector<int> expected_vec = {};
        
        assert(deleted == 3);
        assert(vec == expected_vec);
    }

    //No elements are greater than target
    {
        std::vector<int> vec = {1, 2, 3};
        int deleted = removeElementsGreaterThan(vec, 10);
        std::vector<int> expected_vec = {1, 2, 3};
        
        assert(deleted == 0);
        assert(vec == expected_vec);
    }

    std::cout << "All Tests passed\n";
}

int main() {
    test_removeElementsGreaterThan();
    return 0;
}