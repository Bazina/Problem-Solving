#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve() {
    ll n;
    cin >> n;
    if (n & 1) {
        cout << "YES\n";
    } else {
        do {
            n /= 2;
        } while (!(n & 1) && n != 1);
        if (n == 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}