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
const int MAXN = 1e3;
const int mod = 1e9 + 7;
int dp[MAXN][MAXN], offset = 0, step = 0, ans = 0;
string s1, s2;

int recur(int i, int j) {
    if (i == 0 && j == 0)
        return 0;

    if (~dp[i][j])
        return dp[i][j];

    int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;
    if (i != 0 && j != 0 && s1[i - 1] == s2[j - 1])
        return dp[i][j] = recur(i - 1, j - 1);
    if (i != 0 && j != 0)
        ans1 = 1 + recur(i - 1, j - 1);
    if (i != 0)
        ans2 = 1 + recur(i - 1, j);
    if (j != 0)
        ans3 = 1 + recur(i, j - 1);

    return dp[i][j] = min({ans1, ans2, ans3});
}

void build(int i, int j) {
    if (i == 0 && j == 0)
        return;

    if (i != 0 && j != 0 && s1[i - 1] == s2[j - 1]) {
        build(i - 1, j - 1);
    } else if (j != 0 && recur(i, j) == recur(i, j - 1) + 1) {
        build(i, j - 1);
        ++offset;
        cout << ++step << " Insert " << i + offset << "," << s2[j - 1] << "\n";
    } else if (i != 0 && recur(i, j) == recur(i - 1, j) + 1) {
        build(i - 1, j);
        cout << ++step << " Delete " << i + offset << "\n";
        offset--;
    } else if (recur(i, j) == recur(i - 1, j - 1) + 1) {
        build(i - 1, j - 1);
        cout << ++step << " Replace " << i + offset << "," << s2[j - 1] << "\n";
    }
}

int iter() {
    for (int i = 0; i <= s2.size(); ++i)
        dp[0][i] = i;
    for (int i = 1; i <= s1.size(); ++i)
        dp[i][0] = i;

    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    return dp[s1.size()][s2.size()];
}

void solve() {
    bool printed = false;
    while (getline(cin, s1) && getline(cin, s2)) {
        if (printed)
            cout << "\n";
        printed = true;

        memset(dp, -1, sizeof dp);
        step = offset = 0;
        ans = recur((int) s1.size(), (int) s2.size());

        cout << ans << "\n";
        build((int) s1.size(), (int) s2.size());

    }
}

int main() {
    //IOS
    solve();
    return 0;
}