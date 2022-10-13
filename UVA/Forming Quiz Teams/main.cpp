#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
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
int mod = 1e9 + 7;
ld dp[66000];
int n, t;
pair<int, int> houses[18];

ld calc_dist(ll x1, ll y1, ll x2, ll y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

ld recur(int mask) {
    if (mask == (1 << (2 * n)) - 1)
        return 0;

    ld &ans = dp[mask];
    if (ans != 0)
        return ans;
    ans = 1e18;

    for (int i = 1; i <= 2 * n; ++i) {
        if ((mask >> (i - 1)) & 1)
            continue;

        for (int j = i + 1; j <= 2 * n; ++j) {
            if ((mask >> (j - 1)) & 1)
                continue;

            ans = min(ans, calc_dist(houses[i].first, houses[i].second,
                                     houses[j].first, houses[j].second) +
                               recur((mask | (1 << (i - 1)) | ((1 << (j - 1))))));
        }
    }

    return ans;
}

void solve() {
    while (cin >> n && n != 0) {
        string s;
        for (int i = 1; i <= 2 * n; ++i)
            cin >> s >> houses[i].first >> houses[i].second;

        houses[0].first = houses[0].second = 0;
        memset(dp, 0, sizeof dp);

        printf("Case %d: %.2Lf\n", t++, recur(0));
    }
}

int main() {
    IOS
    t = 1;
    solve();
    return 0;
}