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
vector<vector<int>> dp;
string s1, s2;
int ans;

int recur(int i, int j) {
    if (i == 0 || j == 0)
        return 0;

    if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = 1 + recur(i - 1, j - 1);
        return dp[i][j];
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = max(recur(i - 1, j), recur(i, j - 1));
    return dp[i][j];
}

void solve() {
    while (getline(cin , s1) && getline(cin , s2)) {
        dp.clear();
        dp.resize(1001, vector<int>(1001, -1));
        cout << recur((int) s1.size(), (int) s2.size()) << '\n';
    }
}

int main() {
    IOS
    solve();
    return 0;
}