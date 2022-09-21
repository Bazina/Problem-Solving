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
const int MAXN = 1e4;
const int mod = 1e9 + 7;
int dp[MAXN][MAXN], ans = 0;
string s;

int iter() {
    for (int i = 0; i < s.size(); ++i)
        for (int j = 0; j < s.size(); ++j)
            dp[i][j] = 1e9;

    dp[0][s.size() - 1] = 0;

    for (int i = 0; i < s.size(); ++i) {
        for (int j = (int) s.size() - 1; j >= i; --j) {
            dp[i + 1][j] = min(1 + dp[i][j], dp[i + 1][j]);
            if (j)
                dp[i][j - 1] = min(1 + dp[i][j], dp[i][j - 1]);

            if (s[i] == s[j])
                dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j]);
        }
    }

    int mn = 1e9;
    for (int i = 0; i < s.size(); ++i) {
        if (i)
            mn = min(dp[i][i - 1], mn);
        mn = min(dp[i][i], mn);
    }

    return mn;
}

void solve() {
    cin >> s;

    ans = iter();

    cout << ans << "\n";
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}