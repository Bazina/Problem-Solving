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
vector<int> seq;
int n;

int recur(int i, int l) {
    if (i > n)
        return 0;
    if (dp[i][l] != -1)
        return dp[i][l];

    int ans1 = 0, ans2, ans;

    if (seq[i] > seq[l])
        ans1 = 1 + recur(i + 1, i);

    ans2 = recur(i + 1, l);

    dp[i][l] = ans = max(ans1, ans2);
    return ans;
}

void solve() {
    cin >> n;
    dp.resize(30, vector<int>(30, -1)), seq.resize(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> seq[i];

    cout << recur(1, 0);
}

int main() {
    IOS
    solve();
    return 0;
}