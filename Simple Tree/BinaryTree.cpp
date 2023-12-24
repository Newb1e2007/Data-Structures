#include "BinaryTree.h"

using namespace std;

//====================================== Node

template<typename T>
Node<T>::Node() {
    _parent = nullptr;
    Children::_left_child = nullptr;
    Children::_right_child = nullptr;
}

template<typename T>
Node<T>::Node(const Node<T>& other) : data(data) {
    _parent = other->_parent;
    Children::_left_child = other->_left_child;
    Children::_right_child = other->_right_child;
    tree = other->tree;
}

template<typename T>
Node<T>::Node(T val) : data(data) {
    
}