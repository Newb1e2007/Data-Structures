#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <compare>

using namespace std;

//===============================================

template<typename T>
class BinaryTree;

template<typename T>
class Node;

//===============================================

template<typename T>

class Node {
    friend class BinaryTree<T>;

public:
    Node<T> ();
    Node<T> (const Node<T>& other) : data(data);
    Node<T> (T val) : data(data);
    ~Node<T> ();

    const T* get_const_data();
    T* get_data();
    Node<T>* get_children();
    Node<T>* get_left_child();
    Node<t>* get_right_child();

    friend auto operator<=> (const Node& a, const Node& b); // почему friend?
    friend bool operator== (const Node& a, const Node& b);

private:
    enum Children : Node<T>* { _left_child, _right_child };
    Node<T>* _parent;
    T data;
    BinaryTree<T>* tree;
};

//==================================================

template<typename T> 

class BinaryTree {  
public:
    BinaryTree<T> ();
    BinaryTree<T> (const BinaryTree<T>& other);
    BinaryTree<T> (T first, ...);
    ~BinaryTree<T> ();

    Node<T>* __find_parent(const T& val);
    
    Node<T>* begin();
    Node<T>* end();

    void insert(const T val);
    void erase(const Node<T>* node);
    void erase(T val);
    int size() const;
    bool empty() const;

    istream& operator<< (istream& os, const BinaryTree& bt);
    istream& operator>> (istream& in, BinaryTree& bt);

private:
    Node<T>* _root;
    int _size;
};
