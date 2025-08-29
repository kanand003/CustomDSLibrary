#include "CustomTree.h"
#include <string>

template<typename T>
CustomTree<T>::CustomTree() : root(nullptr) {}

template<typename T>
CustomTree<T>::~CustomTree() {
    clear();
}

template<typename T>
void CustomTree<T>::Insert(const T& value) {
    root = insert(root, value);
}

template<typename T>
typename CustomTree<T>::Node* CustomTree<T>::insert(Node* node, const T& value) {
    if (!node) return new Node(value);
    if (value < node->data) node->left = insert(node->left, value);
    else if (value > node->data) node->right = insert(node->right, value);
    return node;
}

template<typename T>
bool CustomTree<T>::search(const T& value) {
    Node* current = root;
    while (current) {
        if (value == current->data) return true;
        else if (value < current->data) current = current->left;
        else current = current->right;
    }
    return false;
}

template<typename T>
void CustomTree<T>::remove(const T& value) {
    root = remove(root, value);
}

template<typename T>
typename CustomTree<T>::Node* CustomTree<T>::findMin(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}

template<typename T>
typename CustomTree<T>::Node* CustomTree<T>::remove(Node* node, const T& value) {
    if (!node) return nullptr;

    if (value < node->data) node->left = remove(node->left, value);
    else if (value > node->data) node->right = remove(node->right, value);
    else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }
    return node;
}

template<typename T>
void CustomTree<T>::inorder() {
    inorder(root);
    std::cout << std::endl;
}

template<typename T>
void CustomTree<T>::inorder(Node* node) {
    if (!node) return;
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

template<typename T>
void CustomTree<T>::preorder() {
    preorder(root);
    std::cout << std::endl;
}

template<typename T>
void CustomTree<T>::preorder(Node* node) {
    if (!node) return;
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

template<typename T>
void CustomTree<T>::postorder() {
    postorder(root);
    std::cout << std::endl;
}

template<typename T>
void CustomTree<T>::postorder(Node* node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
}

template<typename T>
void CustomTree<T>::clear() {
    clear(root);
    root = nullptr;
}

template<typename T>
void CustomTree<T>::clear(Node* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

template <typename T>
void CustomTree<T>::Display() {
    display(root, 0);
}

template <typename T>
void CustomTree<T>::display(Node* node, int space) {
    if (!node) return;
    space += 5;
    display(node->right, space);

    std::cout << std::endl;
    for (int i = 5; i < space; i++)
        std::cout << " ";
    std::cout << node->data << "\n";

    display(node->left, space);
}

// Explicit add for whatever datatype you need
template class CustomTree<int>;
template class CustomTree<double>;
template class CustomTree<std::string>;
