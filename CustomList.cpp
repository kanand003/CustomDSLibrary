#include "CustomList.h"
#include <string>
#include <iostream>

template <typename T>
CustomList<T>::CustomList() : head(nullptr), tail(nullptr), count(0) {}

template<typename T>
CustomList<T>::~CustomList() {
    clear();
}

template<typename T>
void CustomList<T>::push_front(const T& value) {
    Node* node = new Node(value);
    node->next = head;
    head = node;
    if (count == 0) {
        tail = node;
    }
    ++count;
}

template<typename T>
void CustomList<T>::push_back(const T& value) {
    Node* node = new Node(value);
    if (!head) {
        head = tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
    ++count;
}

template<typename T>
void CustomList<T>::pop_front() {
    if (!head) return; // if empty, nothing to pop - fixed missing semicolon

    Node* temp = head; // Store head
    head = head->next; // Move to next Node
    delete temp; // Delete Head
    --count; // Reduce Count

    if (count == 0) {
        tail = nullptr;
    }
}

template<typename T>
void CustomList<T>::pop_back() {
    if (!head) { return; }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* curr = head;
        while (curr->next != tail) {
            curr = curr->next; // traverse till end
        }
        delete tail;
        tail = curr; // Set new tail
        tail->next = nullptr;
    }
    --count;
}

template<typename T>
T& CustomList<T>::get(size_t index) {
    if (index >= count) {
        throw std::out_of_range("index out of bounds");
    }
    Node* curr = head;
    for (size_t i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->data;
}

template<typename T>
void CustomList<T>::insert(size_t index, const T& value) {
    if (index > count) throw std::out_of_range("Index out of bounds");
    if (index == 0) return push_front(value);
    if (index == count) return push_back(value);

    Node* prev = head;
    for (size_t i = 0; i < index - 1; ++i)
        prev = prev->next;

    Node* node = new Node(value);
    node->next = prev->next;
    prev->next = node;
    ++count;
}

template<typename T>
void CustomList<T>::remove(size_t index) {
    if (index >= count) throw std::out_of_range("Index out of bounds");
    if (index == 0) return pop_front();

    Node* prev = head;
    for (size_t i = 0; i < index - 1; ++i)
        prev = prev->next;

    Node* toDelete = prev->next;
    prev->next = toDelete->next;
    if (toDelete == tail) tail = prev;
    delete toDelete;
    --count;
}

// Added erase function to remove a range of elements
template<typename T>
void CustomList<T>::erase(size_t start, size_t end) {
    if (start >= count || end > count || start >= end) {
        return;
    }

    for (size_t i = start; i < end && i < count; ++i) {
        remove(start); // Keep removing at the start position
    }
}

// Added front function
template<typename T>
T& CustomList<T>::front() {
    if (!head) throw std::out_of_range("List is empty");
    return head->data;
}

// Added back function
template<typename T>
T& CustomList<T>::back() {
    if (!tail) throw std::out_of_range("List is empty");
    return tail->data;
}

// Added getSize function
template<typename T>
size_t CustomList<T>::getSize() const {
    return count;
}

template<typename T>
void CustomList<T>::clear() {
    while (!empty())
        pop_front();
}

template<typename T>
size_t CustomList<T>::size() const {
    return count;
}

template<typename T>
bool CustomList<T>::empty() const {
    return count == 0;
}

template<typename T>
void CustomList<T>::drawList() const {
    // Count
    std::cout << "Count: " << count << " | ";

    // Head value
    if (head)
        std::cout << "Head: " << head->data << " | ";
    else
        std::cout << "Head: NULL | ";

    // Tail value
    if (tail)
        std::cout << "Tail: " << tail->data << "\n";
    else
        std::cout << "Tail: NULL\n";

    // List visual representation
    std::cout << "head";
    Node* curr = head;
    while (curr) {
        std::cout << " → [" << curr->data << "]";
        curr = curr->next;
    }
    std::cout << " → NULL\n";
}

template class CustomList<int>;
template class CustomList<double>;
template class CustomList<std::string>;