#include "Vector.h"
#include <bits/stdc++.h>

Vector::Vector(int n, int val = 0) : _size(n) {
    assert(n >= 0); 
    _begin = new int[_size];
    _end = _begin + _size;
    assign(val);
}

Vector::Vector(const Vector& other) : _size(other._size) {
    _begin = new int[other._size];
    _end = _begin + other._size;
    memcpy(_begin, other._begin, _size*sizeof(int));
}

Vector::~Vector() {
    delete [] _begin;
}

void Vector::reverse() const {
    _reversed = !_reversed;
    return;
}

void Vector::assign(int val) {
    for (int i = 0; i < _count; i++) {
        _begin[i] = val;
    }
    return;
}

void Vector::add(int x) {
    if (_size - _count > 0) {
        _begin[_count] = x;
        _count++;
    } else {
        int* new_begin = new int[_size*2];
        memcpy(_begin, new_begin, _count*sizeof(int));
        delete [] _begin;
        _begin = new_begin;
        _begin[_count] = x;
        _count++;
    }
}

void Vector::del(int l, int r) { // полуинтервал
    assert(l >= 0 && r <= _size);
    memmove(_begin + l, _begin + r, (_size - r) * sizeof(int));
    _size -= r - l;
    _end -= r - l;
}

void Vector::insert(int pos, int x) {
    /*if (_size - _count > 0) {
        for (int i = _count - 1; i >= pos; i++) {
            _begin[i + 1] = _begin[i];
        }
    } else {
        int* new_begin = new int[_size*2];
        memcpy(_begin, new_begin, _count*sizeof(int));
        delete [] _begin;
        _begin = new_begin;
        for (int i = _count - 1; i >= pos; i++) {
            _begin[i + 1] = _begin[i];
        }
    }
    _begin[pos] = x;
    _count++;*/

    if (_size  > _count) {
        memmove(_begin + pos + 1, _begin + pos, (_count - pos) * sizeof(int));
    } else {
        int* new_begin = new int[_size*2];
        _size *= 2;
        memcpy(new_begin, _begin, (pos) * sizeof(int));
        memcpy(new_begin + pos + 1, _begin + pos, (_count - pos) * sizeof(int));
        delete [] _begin;
        _begin = new_begin;
    }
    _begin[pos] = x;
    _count++;
}
