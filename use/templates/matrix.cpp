#include <iostream>
#include <string>
#include <cassert>

template <typename T, int N, int M>
class Matrix {
private:
    T data[N][M];

public:
    void set(int row, int col, T value) {
        data[row][col] = value;
    }

    T get(int row, int col) const {
        return data[row][col];
    }

    void print() const {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    Matrix<T, N, M> operator+(const Matrix<T, N, M>& other) const {
        Matrix<T, N, M> result;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                result.set(i, j, data[i][j] + other.get(i, j));
            }
        }
        return result;
    }
};

void test_Matrix() {
    Matrix<int, 2, 2> m1;
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(1, 0, 3);
    m1.set(1, 1, 4);

    Matrix<int, 2, 2> m2;
    m2.set(0, 0, 5);
    m2.set(0, 1, 6);
    m2.set(1, 0, 7);
    m2.set(1, 1, 8);

    Matrix<int, 2, 2> sumInt = m1 + m2;
    
    assert(sumInt.get(0, 0) == 6);
    assert(sumInt.get(0, 1) == 8);
    assert(sumInt.get(1, 0) == 10);
    assert(sumInt.get(1, 1) == 12);

    std::cout << "Integer Matrix Sum:\n";
    sumInt.print();

    Matrix<double, 2, 1> d1;
    d1.set(0, 0, 1.5);
    d1.set(1, 0, 2.5);

    Matrix<double, 2, 1> d2;
    d2.set(0, 0, 3.0);
    d2.set(1, 0, 4.0);

    Matrix<double, 2, 1> sumDouble = d1 + d2;
    
    assert(sumDouble.get(0, 0) == 4.5);
    assert(sumDouble.get(1, 0) == 6.5);

    std::cout << "Double Matrix Sum:\n";
    sumDouble.print();

    Matrix<std::string, 1, 2> s1;
    s1.set(0, 0, "Hello");
    s1.set(0, 1, "C++");

    Matrix<std::string, 1, 2> s2;
    s2.set(0, 0, " World");
    s2.set(0, 1, " Templates");

    Matrix<std::string, 1, 2> sumString = s1 + s2;
    
    assert(sumString.get(0, 0) == "Hello World");
    assert(sumString.get(0, 1) == "C++ Templates");

    std::cout << "String Matrix Sum:\n";
    sumString.print();

    std::cout << "All tests passed!\n";
}

int main() {
    test_Matrix();
    return 0;
}