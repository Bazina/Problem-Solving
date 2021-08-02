#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int box[n];
    for (int i = 0; i < n; ++i) {
        cin >> box[i];
    }
    sort(box, box + n);
    for (int i = 0; i < n; ++i) {
        cout << box[i] << " ";
    }
}