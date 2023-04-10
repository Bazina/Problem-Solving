#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve() {
    int n, x;
    cin >> n;
    bool exist[51] = {false};
    for (int i = 1; i <= 2 * n; ++i) {
        cin >> x;
        if (!exist[x]) {
            exist[x] = true;
            cout << x << " ";
        }
    }

    cout << '\n';
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}