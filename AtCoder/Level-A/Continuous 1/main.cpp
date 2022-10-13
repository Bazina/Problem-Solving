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
const int MAXN = 1e6;
const int mod = 1e9 + 7;
string s;

void solve() {
    int k, n, ans = 0, one_cnt = 0;
    cin >> n >> k;
    cin >> s;
    vector<int> ones(n + 1), zeros(n + 1);

    for (int i = 0; i < n; ++i) {
        zeros[i + 1] += zeros[i];
        ones[i + 1] += ones[i];

        if (s[i] == '0')
            zeros[i + 1] += 1;
        else if (s[i] == '1') {
            ones[i + 1] += 1;
            one_cnt++;
        }
    }

    for (int i = 1; i <= n - k + 1; ++i) {
        if (ones[i + k - 1] - ones[i - 1] == one_cnt && zeros[i + k - 1] - zeros[i - 1] == 0)
            ans++;
    }

    cout << ((ans == 1) ? "Yes" : "No") << "\n";
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}