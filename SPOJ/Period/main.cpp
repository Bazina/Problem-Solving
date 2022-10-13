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
int fail[N], c = 0;

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

void solve() {
    int n;
    string s;
    set<pair<int, int>> ans;
    cin >> n >> s;

    kmp(s);
    for (int i = 2; i <= s.size(); ++i) {
        int last = fail[i - 1];

        if (i % (i - last) == 0 && last != 0)
            ans.emplace(i, i / (i - last));
    }

    for (auto i: ans)
        cout << i.first << " " << i.second << '\n';
}

int main() {
    IOS
    int t = 1;
    cin >> t;
    while (t--) {
        c++;
        cout << "Test case #" << c << '\n';
        solve();
        cout << '\n';
    }
    return 0;
}