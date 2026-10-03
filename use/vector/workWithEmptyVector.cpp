 #include <iostream>
 #include <vector>
 #include <cassert>
std::vector<int> workWithEmptyVector(){
    std::vector<int> vec;
    for(int i = 0; i < 10; ++i){
        vec.push_back(i+1);
        std::cout<<"size: "<< vec.size() << "\n";
        std::cout<<"capacity: "<< vec.capacity() << "\n";
    }
    std::cout << "All elements: \n";
    for(int i =0; i< 10; ++i){
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
    return vec;
}
void test() {
    std::vector<int> result = workWithEmptyVector();
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(result == expected);
    assert(result.size() == 10);
    assert(result.capacity() >= 10);
    
    std::cout << "All tests passed\n";
}
 int main(){
    test();
}