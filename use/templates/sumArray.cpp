#include <iostream>
#include <string>
#include <cassert>

template <typename T>
T sumArray(T* arr, int size) {
    T sum = T();
    
    for (int i = 0; i < size; ++i) {
        sum = sum + arr[i];
    }
    
    return sum;
}

void test_sumArray() {
    int arr_int[] = {1, 2, 3, 4, 5};
    int sum_int = sumArray(arr_int, 5);
    assert(sum_int == 15);

    double arr_double[] = {1.5, 2.5, 3.5};
    double sum_double = sumArray(arr_double, 3);
    assert(sum_double == 7.5);

    std::string arr_string[] = {"Picsart", " ", "Academy"};
    std::string sum_string = sumArray(arr_string, 3);
    assert(sum_string == "Picsart Academy");

    std::cout << "All tests passed!\n";
}

int main() {
    test_sumArray();
    return 0;
}