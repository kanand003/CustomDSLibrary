#include "CustomVector.h"
#include <string>
#include <iostream>

template <typename T>
void MyVector<T>::reallocate(int minCapacity) {
    int newCapacity = capacity > 0 ? capacity : 1;

    // Exponential growth: double until it satisfies minCapacity
    while (newCapacity < minCapacity) {
        newCapacity *= 2;
    }

    T* temp = new T[newCapacity];
    for (int i = 0; i < size; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
    capacity = newCapacity;
}

template <typename T>
MyVector<T>::MyVector() {
    arr = new T[1];
    capacity = 1;
    size = 0;
}

template <typename T>
MyVector<T>::MyVector(const MyVector& other) {
    capacity = other.capacity;
    size = other.size;
    arr = new T[capacity];
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

template <typename T>
MyVector<T>::~MyVector() {
    delete[] arr;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
    if (this != &other) {
        delete[] arr;
        capacity = other.capacity;
        size = other.size;
        arr = new T[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
MyVector<T>::MyVector(MyVector&& other) {
    arr = other.arr;
    capacity = other.capacity;
    size = other.size;

    other.arr = nullptr;
    other.capacity = 0;
    other.size = 0;
}

// Move Assignment Operator
template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& other) {
    if (this != &other) {
        delete[] arr;

        arr = other.arr;
        capacity = other.capacity;
        size = other.size;

        other.arr = nullptr;
        other.capacity = 0;
        other.size = 0;
    }
    return *this;
}

template <typename T>
T& MyVector<T>::operator[](int index) {
    return arr[index];
}

template <typename T>
const T& MyVector<T>::operator[](int index) const {
    return arr[index];
}

template <typename T>
T& MyVector<T>::at(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return arr[index];
}

template <typename T>
T& MyVector<T>::front() const {
    if (size == 0) throw std::out_of_range("Vector is empty");
    return arr[0];
}

template <typename T>
T& MyVector<T>::back() const {
    if (size == 0) throw std::out_of_range("Vector is empty");
    return arr[size - 1];
}

template <typename T>
int MyVector<T>::getSize() const {
    return size;
}

template <typename T>
int MyVector<T>::getCapacity() const {
    return capacity;
}

template <typename T>
bool MyVector<T>::isEmpty() {
    return size == 0;
}

template <typename T>
void MyVector<T>::reserve(int n) {
    if (n > capacity) {
        reallocate(n);
    }
}

template <typename T>
void MyVector<T>::resize(int n) {
    if (n > capacity) {
        reallocate(n);
    }
    for (int i = size; i < n; ++i) {
        arr[i] = T();
    }
    size = n;
}

template <typename T>
void MyVector<T>::push_back(T data) {
    if (size >= capacity) {
        reallocate(size + 1);
    }
    arr[size++] = data;
}

template <typename T>
void MyVector<T>::pop_back() {
    if (size > 0) {
        --size;
    }
    else {
        throw std::out_of_range("Vector is already empty");
    }
}
template <typename T>
void MyVector<T>::shrink_to_fit() { // Used to reduce memory usage
    if (capacity > size) {
        reallocate(size);
    }
}


template <typename T>
void MyVector<T>::clear() {
    size = 0;
}

template <typename T>
void MyVector<T>::insert(T data, int position) {
    if (position < 0 || position > size) {
        throw std::out_of_range("Out of Range");
    }
    if (size == capacity) {
        reallocate(capacity == 0 ? 1 : 2 * capacity);
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = data;
    size++;
}

template <typename T>
void MyVector<T>::erase(int startrange, int endrange) {
    if (startrange < 0 || endrange > size || startrange >= endrange) {
        throw std::out_of_range("Invalid Range");
    }
    int rangeLen = endrange - startrange;
    for (int i = startrange; i < size - rangeLen; i++) {
        arr[i] = arr[i + rangeLen];
    }
    size = size - rangeLen;
}

template <typename T>
typename MyVector<T>::MyVectorIterator MyVector<T>::begin() {
    return MyVectorIterator(arr);
}

template <typename T>
typename MyVector<T>::MyVectorIterator MyVector<T>::end() {
    return MyVectorIterator(arr + size); // arr+size to point towards one element past the end
}

template class MyVector<int>;
template class MyVector<double>;
template class MyVector<std::string>;