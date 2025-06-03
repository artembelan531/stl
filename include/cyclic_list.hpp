/* Belan Artem Vladislavovich
./stl st135609@student.spbu.ru*/
#pragma once

#include <iostream>
#include <iterator>
#include <stdexcept>

template<typename T>
class CyclicList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* tail;
    size_t count;

public:
    class Iterator {
    private:
        Node* node;
        Node* start;
        bool started;

    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type        = T;
        using difference_type   = std::ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;

        Iterator(Node* node, Node* start)
            : node(node), start(start), started(false) {}

        T& operator*() const { return node->data; }

        Iterator& operator++() {
            if (node) {
                node = node->next;
                if (node == start && started) node = nullptr;
                started = true;
            }
            return *this;
        }

        bool operator==(const Iterator& other) const { return node == other.node; }
        bool operator!=(const Iterator& other) const { return node != other.node; }
    };

    CyclicList() : tail(nullptr), count(0) {}
    ~CyclicList() { clear(); }

    void push_back(const T& value) {
        Node* node = new Node(value);
        if (!tail) {
            tail = node;
            tail->next = tail;
        } else {
            node->next = tail->next;
            tail->next = node;
            tail = node;
        }
        ++count;
    }

    void pop_back() {
        if (!tail) throw std::underflow_error("List is empty");
        if (tail->next == tail) {
            delete tail;
            tail = nullptr;
        } else {
            Node* cur = tail->next;
            while (cur->next != tail) cur = cur->next;
            cur->next = tail->next;
            delete tail;
            tail = cur;
        }
        --count;
    }

    size_t size() const { return count; }
    bool empty() const { return count == 0; }

    void clear() {
        while (!empty()) pop_back();
    }

    Iterator begin() const { return tail ? Iterator(tail->next, tail->next) : end(); }
    Iterator end() const { return Iterator(nullptr, nullptr); }
};
