#include <iostream>
#include <assert.h>

//declaration ===========================================================

template<typename T>
class List;

template<typename T>
class ConstIterator;

template<typename T>
class Iterator;

template<typename T>
class ListNode;


template<typename T>
std::ostream& operator<<(std::ostream&, const List<T>&);

//classes ===============================================================

template<typename T>
class List
{
public:
    List<T> () {
        _head = nullptr; 
        _tail = nullptr;
    }
    List<T> (int n, T defVal) {
        _head = nullptr; 
        _tail = nullptr;
        for(int i = 0; i < n; i++) {
            add(defVal);
        }
    }
    List<T> (T val) { // вроде может быть undefined behavior если T = int
        _head = nullptr; 
        _tail = nullptr;
        add(val);
    }
    List<T> (List<T> *l) {
        _head = nullptr; 
        _tail = nullptr;
        ListNode<T>* iter = l->_head;
        while(iter) {
            add(iter->body());
            iter = iter->_next;
        }
    }
    ListNode<T>* head() const {
        return _head;
    }
    ListNode<T>* tail() const {
        return _tail;
    }
    void add(const T& val);
    void insert_after(ListNode<T> *node, const T& val);
    void insert_before(ListNode<T> *node, const T& val);
    void deleteNode(ListNode<T> *node);
    T detouch(ListNode<T> *node);

    List<T> selctSublist(bool (* valid)(const T&));

    friend std::ostream& operator<< <>(std::ostream&, const List&);


    //typedef Iterator<T> iterator;
    //typedef Iterator<T> iterator;

private:
    ListNode<T> *_head;
    ListNode<T> *_tail;
};



template<typename T>
class ListNode
{
friend class List<T>;
public:
    ListNode<T> () {}
    ListNode<T> (T val) : _body(val) {
        _list = nullptr;
        _next = nullptr;
        _prev = nullptr;
    }
    ListNode<T>* prev() {
        return _prev;
    }
    ListNode<T>* next() {
        return _next;
    }
    T& body() {
        return _body;
    }
private:
    List<T> *_list;
    ListNode<T> *_next;
    ListNode<T> *_prev;
    T _body;
};



template<typename T>
class ConstIterator: public std::iterator<std::input_iterator_tag, ValueType> {
friend class ListNode;
public:
    ConstIterator<T> (const ConstIterator &it) : ptr(it.ptr) {}

    bool operator!=(const ConstIterator &other) const;
    bool operator==(const ConstIterator &other) const;
    ConstIterator&operator++();
    typename ConstIterator::reference operator*() const;
private:
    T *ptr;
    ConstIterator<T> (T *p) : ptr(p) {}
};



template<typename T>
class Iterator(ConstIterator) {
    
};


//realisation ===============================================================

template<typename T>
inline void List<T>::add(const T& val) {
    ListNode<T> *newOne = new ListNode<T>(val);
    newOne->_body = val;
    newOne->_list = this;
    newOne->_prev = _tail;

    if(_head == nullptr) {
        _head = newOne;
    }
    
    if(_tail != nullptr) {
        _tail->_next = newOne;
    }
    _tail = newOne;
}

template<typename T>
inline void List<T>::insert_after(ListNode<T> *node, const T& val) {
    assert(node->_list == this);
    ListNode<T> *newOne = new ListNode<T>;
    newOne->_body = val;
    newOne->list = this;

    newOne->_next = node._next;
    newOne->_prev = node;
    node->_next->_prev = newOne;
    node->_next = newOne;
}

template<typename T>
inline void List<T>::insert_before(ListNode<T> *node, const T& val) {
    assert(node->_list == this);
    ListNode<T> *newOne = new ListNode<T>;
    newOne->_body = val;
    newOne->list = this;

    newOne->_prev = node._prev;
    newOne->_next = node;
    node->_prev->_next = newOne;
    node->_prev = newOne;
}

template<typename T>
inline void List<T>::deleteNode(ListNode<T> *node) {
    assert(node->_list == this);
    if(node->_prev != nullptr) {
        node->_prev->_next = node->_next;
    }
    else {
        _head = node->_next;
    }
    if(node->_next != nullptr) {
        node->_next->_prev = node->_prev;
    }
    else {
        _tail = node->_prev;
    }
    delete node;

}

template<typename T>
inline T List<T>::detouch(ListNode<T> *node) {
    T detouched = node->_body;
    deleteNode(node);
    return detouched;
}

template<typename T>
List<T> List<T>::selctSublist(bool (* valid)(const T&)) {
    List<T> l;
    ListNode<T>* it = this->head();
    while(it) {
        if(valid(it->body())) {
            ListNode<T> *loc = it->next();
            T locT = detouch(it);
            l.add(locT);
            it = loc;
        }
        else {
            it = it->next();
        }
    }
    return l;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const List<T> &l) {
    auto iter = l.head();
    while(iter) {
        os << iter->body() << ' ';
        iter = iter->next();
    }
    return os;
}
