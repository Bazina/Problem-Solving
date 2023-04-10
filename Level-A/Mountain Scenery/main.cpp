#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define srt(a)     (sort((a).begin(), (a).end()))
#define revsrt(a)     (sort((a).rbegin(), (a).rend()))
#define rev(a)  (reverse((a).begin(), (a).end()))
#define coutv(a)     for(int i = 0; i < (a).size(); i++) {cout << (a)[i] << " ";}
#define cinv(a)     for(int i = 0; i < (a).size(); i++){cin >> (a)[i];}
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll MAXN = 1e6 + 5, mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[2 * n + 1];
    for (int i = 0; i < 2 * n + 1; ++i)
        cin >> a[i];

    for (int i = 1; i < 2 * n + 1 && k > 0; i += 2) {
        if (a[i] - 1 > a[i - 1] && a[i] - 1 > a[i + 1]) {
            a[i]--;
            k--;
        }
    }

    for (int i = 0; i < 2 * n + 1; ++i)
        cout << a[i] << ' ';
}

int main() {
    IOS
    solve();
    return 0;
}