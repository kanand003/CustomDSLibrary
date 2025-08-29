#pragma once

template<typename T>
class CustomList {
	struct Node {
		T data;
		Node* next;

		Node(T value) : data(value), next(nullptr) {}
	};
	Node* head;
	Node* tail;
	int count;
public:
	CustomList();
	~CustomList();

	void push_front(const T& value);
	void push_back(const T& value);
	void pop_front();
	void pop_back();

	T& get(size_t index);
	void insert(size_t index, const T& value);
	void remove(size_t index);
	void erase(size_t start, size_t end); 

	T& front(); 
	T& back();  
	size_t getSize() const; 
	size_t size() const;
	bool empty() const;
	void clear();
	void drawList() const;
};