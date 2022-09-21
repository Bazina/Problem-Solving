#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define pi pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pi>
#define all(v)            ((v).begin()), ((v).end())
#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define bsrch(a, n)    (binary_search((a).begin(), (a).end(), n))
#define srt(a)     (sort((a).begin() + 1, (a).end()))
#define revsrt(a)     (sort((a).rbegin(), (a).rend()))
#define rev(a)  (reverse((a).begin(), (a).end()))
#define sum(a)      (accumulate((a).begin(), (a).end(), 0ll))
#define cnt(a, i)  (count((a).begin(), (a).end(), i))
#define coutv(a)     for(int i = 0; i < (a).size(); i++) {cout << (a)[i] << " ";}
#define cinv(a)     for(int i = 0; i < (a).size(); i++){cin >> (a)[i];}
#define cinvP1(a)     for(int i = 0; i < (a).size(); i++){cin >> (a)[i].first;}
#define cinvP2(a)     for(int i = 0; i < (a).size(); i++){cin >> (a)[i].second;}
#define isfind(a, s)  a.find(s) != (a).npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b)    for(int (i) = a; (i) < (b); (i)++)
const int MAXN = 2100;
const int mod = 1e9 + 7;
int n, k;
ll dp[MAXN][MAXN];

ll recur(int l, int num) {
    if (l >= k)
        return 1;
    if (dp[l][num] != -1)
        return dp[l][num];

    ll ans = 0;
    for (int j = num; j <= n; j += num)
        ans += recur(l + 1, j);

    return dp[l][num] = ans % mod;
}

void solve() {
    cin >> n >> k;

    memset(dp, -1, sizeof dp);

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += recur(1, i);
    ans %= mod;

    cout << ans << "\n";
}

int main() {
    IOS
    solve();
    return 0;
}