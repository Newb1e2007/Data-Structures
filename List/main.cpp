#include <bits/stdc++.h>
#include "List.h"

using namespace std;

int main() {
    List<int> arr;
    for (int i = 1; i <= 10; i++) {
        arr.add(i);
    }
    auto i = arr.begin();
    int summ = 0;
    while (i) {
        summ += i->get_data();
        cout << i->get_data() << ' ';
        i = i->get_next();
    }
    cout << '\n' << summ << '\n';
    summ = 0;
    auto j = arr.end();
    while (j) {
        summ += j->get_data();
        cout << j->get_data() << ' ';
        j = j->get_prev();
    }
    cout << '\n' << summ << '\n';
    cout << '\n';

    List<int> evenNum, oddNum;
    auto k = arr.begin();
    while (k) {
        if (k->get_data() % 2 == 1) {
            oddNum.add(k->get_data());
        } else {
            evenNum.add(k->get_data());
        }
        k = k->get_next();
    }
    i = evenNum.begin();
    j = oddNum.begin();
    while (i) {
        cout << i->get_data() << ' ';
        i = i->get_next();
    }
    cout << '\n';
    while (j) {
        cout << j->get_data() << ' ';
        j = j->get_next();
    }
}