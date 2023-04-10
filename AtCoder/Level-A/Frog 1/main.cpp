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
    int n, k = 2;
    cin >> n;
    ll a[n];
    ll dp[n];
    for (int i = 0; i < n; ++i)
        dp[i] = LONG_LONG_MAX;
    dp[0] = 0;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= k && i - j >= 0; ++j) {
            ll p = abs(a[i] - a[i - j]) + dp[i - j];

            dp[i] = min(p, dp[i]);
        }
    }

    cout << dp[n - 1];
}

int main() {
    IOS
    solve();
    return 0;
}