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
const int MAXN = 1e6;
const int mod = 1e9 + 7;
ll t, k, a, b;
ll dp[MAXN], prefix[MAXN];

ll recur(ll rem) {
    if (rem == 0)
        return 1;

    if (dp[rem] != -1)
        return dp[rem];

    ll ans = 0;
    if (rem - k >= 0)
        ans += recur(rem - k);
    ans += recur(rem - 1);
    ans %= mod;
    return dp[rem] = ans;
}

void solve() {
    cin >> t >> k;
    memset(dp, -1, sizeof dp);

    for (int i = 1; i <= 1e5; ++i)
        prefix[i] = (prefix[i - 1] + recur(i)) % mod;

    for (int i = 0; i < t; ++i){
        cin >> a >> b;
        cout << (prefix[b] - prefix[a - 1] + mod) % mod << "\n";
    }
}

int main() {
    IOS
    solve();
    return 0;
}