#include <iostream>

class Array
{
private:
    int _size;
    int* _begin;
    int* _end;
    mutable bool _reversed = false;
public:
    Array(int n, int val = 0);
    Array(const Array& other);
    ~Array();

    //int* begin();
    //int* end();
    //int* next();
    int size() const;
    void assign(int n, int val);
    void reverse() const;

    int& operator[] (int ind);
    int operator[] (int ind) const;
    const Array& operator= (const Array& arr);

    friend std::ostream& operator<< (std::ostream& os, const Array& arr);
};
