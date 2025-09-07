#pragma once
#include <iostream>

template<typename T>
class CustomTree {
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };
    Node* root;

public:
    CustomTree();
    ~CustomTree();
    void Insert(const T& value);
    bool search(const T& value);
    void Remove(const T& value);
    void FindMin();
    void inorder();
    void preorder();
    void postorder();
    void clear();
    void Display();

private:
    Node* insert(Node* node, const T& value);
    Node* findMin(Node* node);
    Node* remove(Node* node, const T& value);
    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);
    void clear(Node* node);
    void display(Node* node, int space);
};
