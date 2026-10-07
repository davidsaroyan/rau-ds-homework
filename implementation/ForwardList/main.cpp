#include "ForwardList.h"
#include <cassert>
#include <iostream>

void test_push_front() {
    ForwardList<int> list;
    list.push_front(1);
    assert(list.size() == 1);
    assert(list.front() == 1);

    list.push_front(2);
    list.push_front(3);
    assert(list.size() == 3);
    assert(list.front() == 3);

    std::cout << "test_push_front passed" << std::endl;
}

void test_pop_front() {
    ForwardList<int> list;
    list.push_front(10);
    list.push_front(20);

    list.pop_front();
    assert(list.size() == 1);
    assert(list.front() == 10);

    list.pop_front();
    assert(list.size() == 0);
    assert(list.empty());

    std::cout << "test_pop_front passed" << std::endl;
}

void test_insert_and_erase_after() {
    ForwardList<int> list;
    list.push_front(10); // [10]
    
    auto* head = list.begin();
    list.insert_after(head, 20); // [10, 20]
    assert(list.size() == 2);
    assert(head->next->data == 20);

    list.erase_after(head); // [10]
    assert(list.size() == 1);
    assert(head->next == nullptr);

    std::cout << "test_insert_and_erase_after passed" << std::endl;
}

void test_reverse() {
    ForwardList<int> list;
    list.push_front(30);
    list.push_front(20);
    list.push_front(10); // [10, 20, 30]

    list.reverse(); // [30, 20, 10]
    assert(list.front() == 30);

    auto* curr = list.begin();
    assert(curr->data == 30);
    assert(curr->next->data == 20);
    assert(curr->next->next->data == 10);

    std::cout << "test_reverse passed" << std::endl;
}

void test_copy_and_assign() {
    ForwardList<int> list1;
    list1.push_front(2);
    list1.push_front(1);

    ForwardList<int> list2 = list1;
    assert(list2.size() == 2);
    assert(list2.front() == 1);

    ForwardList<int> list3;
    list3 = list1;
    assert(list3.size() == 2);
    assert(list3.front() == 1);

    std::cout << "test_copy_and_assign passed" << std::endl;
}

int main() {
    std::cout << "Running ForwardList tests..." << std::endl;
    
    test_push_front();
    test_pop_front();
    test_insert_and_erase_after();
    test_reverse();
    test_copy_and_assign();

    std::cout << "All ForwardList tests passed successfully!" << std::endl;
    return 0;
}