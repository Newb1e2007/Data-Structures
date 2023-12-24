#include <iostream>

using namespace std;


template<typename T>
class List;

template<typename T>
class ListNode;

/*struct Data {
    Data(int nx, int ny, int nz) {
        x = nx;
        y = ny;
        z = nz; 
    }
    ~Data();

    int x;
    int y;
    int z;
};*/

template<typename T>

class ListNode {
    friend class List<T>;
public:
    ListNode<T>(T newData) {
        //_prev = nullptr;
        _next = nullptr;
        data = newData;
    }
    ListNode<T>(const T* newNext, T newData) {
        //_prev = newPrev;
        _next = newNext;
        data = newData;
    }
    ~ListNode<T>();

    //ListNode<T>* get_prev();
    ListNode<T>* get_next();
    T get_data();
    void reset(ListNode *newNext);

private:
    T data;
    //ListNode<T>* _prev;
    ListNode<T>* _next;
};

template<typename T>
inline void ListNode<T>::reset(ListNode *newNode) {
    _next = newNode;
}

template<typename T>
inline ListNode<T>* ListNode<T>::get_next() {
    return _next;
}   

template<typename T>
inline T ListNode<T>::get_data() {
    return data;
}

template<typename T>

class List {
public:
    List<T>() {
        _begin = nullptr;
        _end = nullptr;
        _size = 0;
        _size_of_el = sizeof(T);
    }
    //List<T>(int size);
    List<T>(const List<T>& other) {
        _begin = nullptr;
        _end = nullptr;
        ListNode<T> *i = other->_begin;
        for (i = i; i != nullptr; i = i->_begin) {
            add(i->data);
        }
        _size = other._size;
        _size_of_el = other._size_of_el;
    }
    ~List<T>() {
        
    }

    int size() const;
    size_t size_of_el() const;
    //void reverse() const;
    void add(const T& other);
    void del(ListNode<T>* node);
    //void delAfter(ListNode<T>* node);
    T detouch(ListNode<T> *node);
    void reset();

    ListNode<T>* begin();
    ListNode<T>* end();

    //friend std::ostream& operator<< <>(std::ostream &os, const List &list);

private:
    ListNode<T>* _begin;
    ListNode<T>* _end;
    //mutable bool _reversed;
    int _size;
    size_t _size_of_el;
};

template <typename T>
inline int List<T>::size() const {
    return _size;
}

template <typename T>
inline ListNode<T>* List<T>::begin() {
    return _begin;
}

template <typename T>
inline ListNode<T>* List<T>::end() {
    return _end;
}

template <typename T> 
inline void List<T>::add(const T& other) {
    ListNode<T> *newNode = new ListNode<T>(other);
    _size++;
    newNode->_next = nullptr;
    //newNode->_prev = _end;
    newNode->data = other;
    if (_begin == nullptr) _begin = newNode;
    if (_end != nullptr) _end->_next = newNode; 
    _end = newNode;
}

template<typename T> 
inline void List<T>::del(ListNode<T>* node) {
    _size--;
    if (_begin != node) {
        auto i = _begin;
        while (i->get_next() != node) {
            i = i->get_next();
        }
        i->_next = node->_next;
    }  
    delete node;
}

template<typename T> 
inline T List<T>::detouch(ListNode<T> *node) {
    T retD = node->data;
    del(node);
    return retD;
}

template<typename T>
inline void List<T>::reset() {
    swap(_begin, _end);
}
