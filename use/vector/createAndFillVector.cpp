#include <vector>
#include <iostream>
#include <cassert>

std::vector<int> createAndFillVector(int n){
            std::vector<int> vec(n);
            for(int i = 0; i < n; ++i){
                    vec[i] = i + 1;
                }
            for(int i = 0; i < n; ++i){
                    std::cout << vec[i] << " ";
                }
            std::cout <<"\nsize: "<< vec.size() << "\n";
            std::cout <<"cap: "<< vec.capacity() << "\n";
            std::cout << "\n"; 
            return vec; 
}

void test(){
        std:: vector<int> vec = createAndFillVector(3);
        std:: vector<int> expected;
        expected.push_back(1);
        expected.push_back(2);
        expected.push_back(3);
        assert(vec == expected);
        assert(createAndFillVector(0).empty());
        expected.pop_back();
        expected.pop_back();
        assert(createAndFillVector(1) == expected);
        std::cout <<"\n" << "CreateAndFillVector passed" << std::endl;
    }

int main(){
        test();
        return 0;
    }
