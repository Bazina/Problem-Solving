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
const int N = 1e6 + 10, mod = 1e9 + 7;
int fail[N], memo[100002][27];
vector<int> dp[100002];
string s, t;

void kmp(string &st) {
    int n = (int) st.size();

    for (int i = 1; i < n; ++i) {
        int j = fail[i - 1];

        while (j > 0 and st[i] != st[j])
            j = fail[j - 1];

        if (st[i] == st[j])
            j++;

        fail[i] = j;
    }
}

int get_next(int j, char x) {
    int temp = j;

    if (~memo[j][x - 'a'])
        return memo[j][x - 'a'];

    while (temp > 0 and x != t[temp])
        temp = fail[temp - 1];

    if (x == t[temp])
        temp++;

    return memo[j][x - 'a'] = temp;
}

int recur(int i, int j) {
    if (i >= s.size())
        return 0;

    if (~dp[i][j])
        return dp[i][j];

    if (s[i] != '?') {
        int ret, temp = get_next(j, s[i]);

        if (temp == t.size()) {
            temp = fail[temp - 1];
            ret = 1 + recur(i + 1, temp);
        } else
            ret = recur(i + 1, temp);

        return dp[i][j] = ret;
    } else {
        int ret = 0;
        for (char k = 'a'; k <= 'z'; k++) {
            int temp = get_next(j, k);

            if (temp == t.size()) {
                temp = fail[temp - 1];
                ret = max(1 + recur(i + 1, temp), ret);
            } else
                ret = max(recur(i + 1, temp), ret);
        }
        return dp[i][j] = ret;
    }
}

void solve() {
    cin >> s >> t;

    memset(memo, -1, sizeof memo);
    for (int i = 0; i < s.size(); ++i)
        dp[i].resize(t.size(), -1);

    kmp(t);

    cout << recur(0, 0);
}

int main() {
    IOS
    solve();
    return 0;
}