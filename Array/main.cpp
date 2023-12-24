#include<bits/stdc++.h>
#include "Array.h"

using namespace std;

int summ(const Array& arr) {
    arr.reverse();
    int summ = 0;
    for (int i = 0; i < arr.size(); i++) {
        summ += arr[i];
    }
    return summ;
}

int main() {
    int n; cin >> n;
    Array arr(n);
    for (int i = 0;  i< n; i++) {
        cin >> arr[i];
    }
    int m, val; cin >> m >> val;
    arr[m - 1] = val;
    arr.reverse();
    int sum = summ(arr);
    cout << sum << ' ' << arr.size() << '\n' << arr;
    return 0;
}