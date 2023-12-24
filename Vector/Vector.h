#include <iostream>

class Vector 
{
public:
    Vector(int n, int val = 0);
    Vector(const Vector& other);
    ~Vector();

    //int* begin();
    //int* end();
    //int* next();

    int size() const;
    int* begin() const;
    int* end() const;
    void reverse() const;
    void assign(int val);

    void push_back(int x);
    void pop_back();
    void add(int x);
    void del(int l, int r);
    void insert(int pos, int x);
    const Vector& subset(int l, int r);

    int& operator[] (int ind);
    int operator[] (int ind) const;
    const Vector& operator= (const Vector& arr);
    const Vector& operator+ (const Vector& other);

    friend std::ostream& operator<< (std::ostream& os, const Vector& arr);
private:
    int _size;
    int _count;
    int* _begin;
    int* _end;
    mutable bool _reversed;
};

inline int Vector::size() const {
    return _count;
}

inline int* Vector::begin() const {
    return _begin;
}

inline int* Vector::end() const {
    return _end;
}

inline void Vector::push_back(int x) {
    this->add(x);
    return;
}

inline void Vector::pop_back() {
    this->del(_count, _count + 1);
    return;
}