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
ll MAXN = 1e5 + 5, mod = 1e9 + 7;
ll dp[102][100000 + 5];
ll n, W;

ll iter(ll a[][2]) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 100000; ++j) {
            if (dp[i - 1][j] == LONG_LONG_MAX)
                continue;

            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            dp[i][j + a[i][1]] = min(dp[i][j + a[i][1]], dp[i - 1][j] + a[i][0]);
        }
    }

    ll ans = 0;
    for (int i = 0; i < 100005; ++i) {
        if (dp[n][i] <= W)
            ans = i;
    }
    return ans;
}

void solve() {
    memset(dp[0], 0, sizeof dp[0]);
    for (int i = 0; i < 102; ++i)
        for (int j = 1; j < 100005; ++j)
            dp[i][j] = LONG_LONG_MAX;

    cin >> n >> W;
    ll a[n + 1][2];
    for (int i = 1; i <= n; ++i)
        cin >> a[i][0] >> a[i][1];

    cout << iter(a) << '\n';
}

int main() {
    IOS
    solve();
    return 0;
}