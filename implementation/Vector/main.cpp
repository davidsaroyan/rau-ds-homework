#include "Vector.h"
#include <cassert>
#include <iostream>

void test_default_constructor() {
    Vector<int> v;
    assert(v.size() == 0);
    assert(v.capacity() == 0);
    assert(v.empty() == true);
    std::cout << "test_default_constructor passed\n";
}

void test_initial_size_constructor() {
    Vector<int> v(5);
    assert(v.size() == 5);
    assert(v.capacity() == 5);
    assert(v.empty() == false);
    assert(v[0] == 0);
    std::cout << "test_initial_size_constructor passed\n";
}

void test_push_back() {
    Vector<int> v;
    v.push_back(5);
    assert(v.size() == 1);
    assert(v[0] == 5);

    v.push_back(10);
    v.push_back(15);
    assert(v.size() == 3);
    assert(v.back() == 15);
    std::cout << "test_push_back passed\n";
}

void test_pop_back() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.pop_back();
    assert(v.size() == 1);
    assert(v.back() == 10);

    v.pop_back();
    assert(v.size() == 0);
    assert(v.empty() == true);
    std::cout << "test_pop_back passed\n";
}

void test_operator_bracket() {
    Vector<int> v;
    v.push_back(100);
    v.push_back(200);
    assert(v[0] == 100);
    assert(v[1] == 200);

    v[0] = 500;
    assert(v[0] == 500);
    std::cout << "test_operator_bracket passed\n";
}

void test_at() {
    Vector<int> v;
    v.push_back(1);
    assert(v.at(0) == 1);

    bool caught = false;
    try {
        v.at(5);
    } catch (const std::out_of_range&) {
        caught = true;
    }
    assert(caught == true);
    std::cout << "test_at passed\n";
}

void test_front_back() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    assert(v.front() == 10);
    assert(v.back() == 30);
    std::cout << "test_front_back passed\n";
}

void test_reserve_capacity() {
    Vector<int> v;
    v.reserve(10);
    assert(v.capacity() == 10);
    assert(v.size() == 0);

    v.push_back(1);
    assert(v.capacity() == 10);
    assert(v.size() == 1);
    std::cout << "test_reserve_capacity passed\n";
}

void test_clear() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.clear();
    assert(v.size() == 0);
    assert(v.empty() == true);
    std::cout << "test_clear passed\n";
}

void test_copy_constructor() {
    Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);

    Vector<int> v2 = v1;
    assert(v2.size() == 2);
    assert(v2[0] == 1);
    assert(v2[1] == 2);

    v1[0] = 99;
    assert(v2[0] == 1);
    std::cout << "test_copy_constructor passed\n";
}

void test_assignment_operator() {
    Vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);

    Vector<int> v2;
    v2 = v1;
    assert(v2.size() == 2);
    assert(v2[0] == 10);
    assert(v2[1] == 20);

    v2 = v2;
    assert(v2.size() == 2);
    std::cout << "test_assignment_operator passed\n";
}

void test_iterators() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    int sum = 0;
    for (int* it = v.begin(); it != v.end(); ++it) {
        sum += *it;
    }
    assert(sum == 6);
    std::cout << "test_iterators passed\n";
}

int main() {
    std::cout << "Running Vector tests...\n";

    test_default_constructor();
    test_initial_size_constructor();
    test_push_back();
    test_pop_back();
    test_operator_bracket();
    test_at();
    test_front_back();
    test_reserve_capacity();
    test_clear();
    test_copy_constructor();
    test_assignment_operator();
    test_iterators();

    std::cout << "All Vector tests passed successfully!\n";
    return 0;
}