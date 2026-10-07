#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <stdexcept>

template <typename T>
class ForwardList {
public:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

private:
    Node* _head;
    int _size;

public:
    ForwardList() : _head(nullptr), _size(0) {}

    ~ForwardList() {
        clear();
    }

    ForwardList(const ForwardList& other) : _head(nullptr), _size(0) {
        if (!other._head) return;
        _head = new Node(other._head->data);
        _size = 1;
        Node* curr = _head;
        Node* other_curr = other._head->next;
        while (other_curr) {
            curr->next = new Node(other_curr->data);
            curr = curr->next;
            other_curr = other_curr->next;
            ++_size;
        }
    }

    ForwardList& operator=(const ForwardList& other) {
        if (this != &other) {
            clear();
            if (other._head) {
                _head = new Node(other._head->data);
                _size = 1;
                Node* curr = _head;
                Node* other_curr = other._head->next;
                while (other_curr) {
                    curr->next = new Node(other_curr->data);
                    curr = curr->next;
                    other_curr = other_curr->next;
                    ++_size;
                }
            }
        }
        return *this;
    }

    void push_front(const T& x) {
        Node* new_node = new Node(x);
        new_node->next = _head;
        _head = new_node;
        ++_size;
    }

    void pop_front() {
        if (_head) {
            Node* temp = _head;
            _head = _head->next;
            delete temp;
            --_size;
        }
    }

    T& front() {
        if (!_head) throw std::out_of_range("List is empty");
        return _head->data;
    }

    const T& front() const {
        if (!_head) throw std::out_of_range("List is empty");
        return _head->data;
    }

    void insert_after(Node* node, const T& value) {
        if (!node) return;
        Node* new_node = new Node(value);
        new_node->next = node->next;
        node->next = new_node;
        ++_size;
    }

    void erase_after(Node* node) {
        if (!node || !node->next) return;
        Node* temp = node->next;
        node->next = temp->next;
        delete temp;
        --_size;
    }

    void clear() {
        while (_head) {
            pop_front();
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = _head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        _head = prev;
    }

    int size() const {
        return _size;
    }

    bool empty() const {
        return _head == nullptr;
    }

    Node* begin() {
        return _head;
    }

    const Node* begin() const {
        return _head;
    }
};

#endif // FORWARDLIST_H