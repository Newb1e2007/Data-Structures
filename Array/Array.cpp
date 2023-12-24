#include "Array.h"
#include <assert.h>
#include <cstring>

Array::Array(int n, int val) : _size(n) {
    assert(n > 0); 
    _begin = new int[_size];
    _end = _begin + _size;
    assign(_size, val);
}

Array::Array(const Array& other) : _size(other._size) {
    assert(other._size == _size);
    _begin = new int[other._size];
    _end = _begin + other._size;
    memcpy(_begin, other._begin, _size*sizeof(int));
} 

Array::~Array() {
    delete [] _begin;
}

int Array::size() const {
    return _size;
}

void Array::assign(int n, int val) {
    assert(n > 0);
    assert(n <= _size);
    for (int i = 0; i < n; i++) {
        _begin[i] = val;
    }
    return;
}

void Array::reverse() const {
    _reversed = !_reversed;
}

int& Array::operator[] (int ind) {
    if (_reversed) ind = _size - ind - 1;
    return _begin[ind];
}

int Array::operator[] (int ind) const {
    if (_reversed) ind = _size - ind - 1;
    return _begin[ind];
}

const Array& Array::operator= (const Array& other) {
    _begin = new int[other._size];
    _end = _begin + other._size;
    memcpy(_begin, other._begin, _size*sizeof(int));
    return *this;
}

std::ostream& operator<< (std::ostream& os, const Array& arr) {
    for (int i = 0; i < arr._size; i++) {
        os << arr[i] << ' ';
    }
    return os;
}
