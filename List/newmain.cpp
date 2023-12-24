#include <bits/stdc++.h>
#include "SimplyConnectedList.h"

using namespace std;

int main() {
    List<int> arr;
    for (int i = 0; i < 10; i++) {
        arr.add(i);
    }
    auto i = arr.begin();
    auto k = i;
    ListNode<int> *prev = nullptr;
    while(i) {
        k = i->get_next();
        i->reset(prev);
        prev = i;
        i = k;
    }
    arr.reset();
    auto j = arr.begin();
    while (j) {
        cout << j->get_data() << ' ';
        j = j->get_next();
    }
}