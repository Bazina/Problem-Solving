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
const int N = 102, mod = 1e9 + 7;
int fail[N], dp[N][N][N];
string s1, s2, v, ans;

void kmp(string &s) {
    int n = (int) s.size();

    for (int i = 1; i < n; ++i) {
        int j = fail[i - 1];

        while (j > 0 and s[i] != s[j])
            j = fail[j - 1];

        if (s[i] == s[j])
            j++;

        fail[i] = j;
    }
}

int recur(int i, int j, int match) {
    if (i == s1.size() || j == s2.size())
        return 0;

    int &ret = dp[i][j][match];
    if (~ret)
        return ret;

    ret = 0;

    if (s1[i] == s2[j]) {
        ret = recur(i + 1, j + 1, match);

        while (match > 0 and s1[i] != v[match])
            match = fail[match - 1];
        if (s1[i] == v[match])
            match++;

        if (match != v.size())
            ret = max(recur(i + 1, j + 1, match) + 1, ret);
    } else {
        ret = max(recur(i, j + 1, match), recur(i + 1, j, match));
    }

    return ret;
}

void build(int i, int j, int match) {
    if (i == s1.size() || j == s2.size())
        return;

    int ret = recur(i, j, match);

    if (s1[i] == s2[j]) {
        if (ret == recur(i + 1, j + 1, match))
            build(i + 1, j + 1, match);
        else {
            ans.push_back(s1[i]);

            while (match > 0 and s1[i] != v[match])
                match = fail[match - 1];
            if (s1[i] == v[match])
                match++;

            build(i + 1, j + 1, match);
        }
    } else {
        if (recur(i, j + 1, match) > recur(i + 1, j, match))
            build(i, j + 1, match);
        else
            build(i + 1, j, match);
    }
}

void solve() {
    cin >> s1 >> s2 >> v;

    kmp(v);

    memset(dp, -1, sizeof dp);
    recur(0, 0, 0);
    build(0, 0, 0);
    if (ans.empty())
        cout << "0";
    else
        cout << ans;
}

int main() {
    IOS
    solve();
    return 0;
}