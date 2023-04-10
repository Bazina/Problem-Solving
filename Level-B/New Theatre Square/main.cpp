#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve() {
    int n, m, x, y, cost = 0;
    char current, previous;
    cin >> n >> m >> x >> y;

    for (int i = 0; i < n; ++i) {
        previous = 'x';
        for (int j = 0; j < m; ++j) {
            cin >> current;
            if (j > 0 and current == '.' and previous == '.' and y < x + x) {
                cost = cost - x + y;
                previous = 'x';
            } else if (current == '.') {
                cost += x;
                previous = current;
            } else {
                previous = 'x';
            }
        }
    }

    cout << cost << '\n';
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}