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
const int MAXN = 1e7 + 5;
const int mod = 1e9 + 7;
int dp[4][MAXN], n;

int iter() {
    dp[3][0] = 1;

    for (int i = 1; i <= n; ++i) {
        dp[3][i] = ((ll) dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % mod;
        dp[0][i] = ((ll) dp[3][i - 1] + dp[1][i - 1] + dp[2][i - 1]) % mod;
        dp[1][i] = ((ll) dp[3][i - 1] + dp[0][i - 1] + dp[2][i - 1]) % mod;
        dp[2][i] = ((ll) dp[3][i - 1] + dp[1][i - 1] + dp[0][i - 1]) % mod;
    }

    return dp[3][n];
}

void solve() {
    cin >> n;
    memset(dp, 0, sizeof dp);
    cout << iter() << "\n";
}

int main() {
    IOS
    solve();
    return 0;
}