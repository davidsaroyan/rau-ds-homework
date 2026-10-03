#include <iostream>
#include <vector>
#include <cassert>

void manageCapacity(std::vector<int>& vec){
    std::cout << "Starting size: " << vec.size() << "\n";
    std::cout << "Starting capacity: " << vec.capacity() << "\n";

    vec.reserve(vec.size() + 500);

    for(int i = 1; i <= 500; ++i){
        vec.push_back(i);
    }

    std::cout << "New size: " << vec.size() << "\n";
    std::cout << "New capacity: " << vec.capacity() << "\n";
}

void test_manageCapacity(){
    std::vector<int> vec;
    vec.push_back(42);
    
    size_t old_size = vec.size();
    
    manageCapacity(vec);

    assert(vec.size() == old_size + 500);
    assert(vec.capacity() >= vec.size());
    assert(vec[old_size] == 1);
    assert(vec.back() == 500);

    std::cout << "All tests passed!\n";
}

int main(){
    test_manageCapacity();
    return 0;
}