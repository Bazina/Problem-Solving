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
int n, c;
ll dp[MAXN][2], stairs[MAXN], elevator[MAXN];

void iter() {
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + stairs[i]);
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + stairs[i]);
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + elevator[i] + c);
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + elevator[i]);
    }
}

void solve() {
    cin >> n >> c;

    for (int i = 2; i <= n; ++i)
        cin >> stairs[i];
    
    for (int i = 2; i <= n; ++i)
        cin >> elevator[i];
    
    memset(dp, mod, sizeof dp);
    dp[1][0] = 0, dp[1][1] = c;
    iter();

    for (int i = 1; i <= n; ++i) {
        cout << min(dp[i][0], dp[i][1]) << " ";
    }
}

int main() {
    IOS
    solve();
    return 0;
}