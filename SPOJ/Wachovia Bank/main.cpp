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
const int MAXN = 2e5 + 10;
vector<vector<int>> dp;
vector<pair<int, int>> bags;
int k, m;

int recur(int bagSize, int i) {
    if (i > m)
        return 0;
    if (dp[i][bagSize] != -1)
        return dp[i][bagSize];

    int ans1 = 0, ans2, ans;

    ans2 = recur(bagSize, i + 1);
    if (bags[i].first <= bagSize)
        ans1 = bags[i].second + recur(bagSize - bags[i].first, i + 1);

    dp[i][bagSize] = ans = max(ans1, ans2);
    return ans;
}

void solve() {
    cin >> k >> m;
    dp.clear(), bags.clear();
    dp.resize(m + 1, vector<int>(k + 1, -1)), bags.resize(m + 1);

    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        bags[i] = {x, y};
    }

    cout << "Hey stupid robber, you can get " << recur(k, 1) << ".\n";
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}