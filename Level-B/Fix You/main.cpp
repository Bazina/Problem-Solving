#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve() {
    int n, m, change = 0;
    cin >> n >> m;
    char grid[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if ((i == n - 1 && j < m - 1 && grid[i][j] == 'D') ||
                (j == m - 1 && i < n - 1 && grid[i][j] == 'R'))
                change++;
        }
    }

    cout << change << '\n';
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}