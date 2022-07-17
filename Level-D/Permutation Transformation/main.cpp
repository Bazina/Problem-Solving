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
#define srt(a)     (sort((a).begin(), (a).end()))
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

vector<int> a, dp;

void dfs(int l, int r, int currDepth) {
    if (l > r)
        return;
    if (l == r) {
        dp[r] = currDepth;
        return;
    }

    int maxi = max_element(a.begin() + l, a.begin() + r + 1) - a.begin();
    dp[maxi] = currDepth;

    dfs(l, maxi - 1, currDepth + 1);
    dfs(maxi + 1, r, currDepth + 1);
}

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    dp.resize(n, 0);

    cinv(a)

    dfs(0, n - 1, 0);
    coutv(dp)
    cout << "\n";
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}