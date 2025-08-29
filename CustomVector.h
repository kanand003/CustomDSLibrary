#pragma once

template <typename T>
class MyVector {
	T* arr;
	int size;
	int capacity;

	void reallocate(int newCapacity);

public:
	MyVector();
	~MyVector();
	MyVector(const MyVector& other);
	MyVector& operator=(const MyVector& other);
	MyVector(MyVector&& other);            // Move Constructor
	MyVector& operator=(MyVector&& other); // Move Assignment


	T& operator[](int index);
	const T& operator[](int index) const;
	T& at(int index);
	T& front() const;
	T& back() const;

	int getSize() const;
	int getCapacity() const;
	bool isEmpty();
	void reserve(int n);
	void resize(int n);

	void push_back(T data);
	void pop_back();
	void shrink_to_fit();
	void clear();
	void insert(T data, int position);
	void erase(int startrange, int endrange);

	class MyVectorIterator {
		T* ptr;
	public:
		MyVectorIterator() : ptr(nullptr) {}
		MyVectorIterator(T* p) : ptr(p) {}

		T& operator*() const { return *ptr; }
		T* operator->() const { return ptr; }

		MyVectorIterator& operator++() { ++ptr; return *this; }
		MyVectorIterator operator++(int) { MyVectorIterator temp = *this; ++ptr; return temp; }
		MyVectorIterator& operator--() { --ptr; return *this; }
		MyVectorIterator operator--(int) { MyVectorIterator temp = *this; --ptr; return temp; }

		bool operator==(const MyVectorIterator& other) const { return ptr == other.ptr; }
		bool operator!=(const MyVectorIterator& other) const { return ptr != other.ptr; }
	};

	MyVectorIterator begin();
	MyVectorIterator end();
};