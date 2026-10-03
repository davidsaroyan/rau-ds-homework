#include <iostream>
#include <string>
#include <cassert>

template <typename T, typename Predicate>
T* filter(T* arr, int size, int& new_size, Predicate pred) {
    new_size = 0;
    for (int i = 0; i < size; ++i) {
        if (pred(arr[i])) {
            new_size++;
        }
    }
    
    T* result = new T[new_size];
    int index = 0;
    
    for (int i = 0; i < size; ++i) {
        if (pred(arr[i])) {
            result[index] = arr[i];
            index++;
        }
    }
    
    return result;
}

bool isEven(const int& x) {
    return x % 2 == 0;
}

bool isPositive(const double& x) {
    return x > 0.0;
}

bool isLong(const std::string& str) {
    return str.length() > 4;
}

void test_filter() {
    int arr_int[] = {1, 2, 3, 4, 5, 6};
    int new_size_int = 0;
    int* res_int = filter(arr_int, 6, new_size_int, isEven);
    assert(new_size_int == 3);
    assert(res_int[0] == 2);
    assert(res_int[1] == 4);
    assert(res_int[2] == 6);
    delete[] res_int;

    double arr_double[] = {-1.5, 3.14, -2.0, 5.5};
    int new_size_double = 0;
    double* res_double = filter(arr_double, 4, new_size_double, isPositive);
    assert(new_size_double == 2);
    assert(res_double[0] == 3.14);
    assert(res_double[1] == 5.5);
    delete[] res_double;

    std::string arr_string[] = {"cat", "apple", "dog", "banana"};
    int new_size_string = 0;
    std::string* res_string = filter(arr_string, 4, new_size_string, isLong);
    assert(new_size_string == 2);
    assert(res_string[0] == "apple");
    assert(res_string[1] == "banana");
    delete[] res_string;

    std::cout << "All tests passed!\n";
}

int main() {
    test_filter();
    return 0;
}