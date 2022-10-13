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
int dp[12][1026];
int n, m, k;
pair<int, int> pos[10];

int recur(int idx, int mask) {
    if (mask == (1 << k) - 1)
        return abs(pos[0].first - pos[idx].first) + abs(pos[0].second - pos[idx].second);

    int &ans = dp[idx][mask];
    if (~ans)
        return ans;
    ans = 1e9;

    for (int i = 1; i <= k; ++i) {
        if ((mask >> (i - 1)) & 1)
            continue;

        ans = min(ans,
                  abs(pos[i].first - pos[idx].first) + abs(pos[i].second - pos[idx].second) +
                  recur(i, mask | (1 << (i - 1))));
    }

    return ans;
}

void solve() {
    cin >> n >> m >> pos[0].first >> pos[0].second >> k;
    for (int i = 1; i <= k; ++i)
        cin >> pos[i].first >> pos[i].second;

    memset(dp, -1, sizeof dp);

    cout << "The shortest path has length " << recur(0, 0) << '\n';
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}