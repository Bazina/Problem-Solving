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
vector<int> coins{1, 5, 10, 25, 50};
vector<vector<int>> dp;
int n;

int recur(int money, int i) {
    if (money == 0)
        return dp[i][money] = 1;
    if (i == 0)
        return 0;
    if (dp[i][money] != -1)
        return dp[i][money];

    if (coins[i - 1] <= money)
        return dp[i][money] = recur(money, i - 1) + recur(money - coins[i - 1], i);
    else
        return dp[i][money] = recur(money, i - 1);
}

void solve() {
    dp.clear();
    dp.resize(10000, vector<int>(10000, -1));
    while (cin >> n && n != 0) {
        cout << recur(n, 5) << '\n';
    }
}

int main() {
    IOS
    solve();
    return 0;
}