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

ll recur(ll a[][2], int i, ll w) {
    if (i >= n || w == 0)
        return 0;

    if (dp[i][w] != -1)
        return dp[i][w];

    ll ans, ans1 = 0, ans2 = 0;

    if (w - a[i][0] >= 0)
        ans1 = recur(a, i + 1, w - a[i][0]) + a[i][1];
    ans2 = recur(a, i + 1, w);

    dp[i][w] = ans = max(ans1, ans2);

    return ans;
}

ll iter(ll a[][2]) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= W; ++j) {
            ll ans1 = 0, ans2;
            if (j - a[i - 1][0] >= 0)
                ans1 = dp[i - 1][j - a[i - 1][0]] + a[i - 1][1];
            ans2 = dp[i - 1][j];

            dp[i][j] = max(ans1, ans2);
        }
    }

    return dp[n][W];
}

void solve() {
    memset(dp, 0, sizeof dp);
    cin >> n >> W;
    ll a[n][2];
    for (int i = 0; i < n; ++i)
        cin >> a[i][0] >> a[i][1];

    //cout << recur(a, 0, W) << '\n';
    cout << iter(a) << '\n';
}

int main() {
    IOS
    solve();
    return 0;
}