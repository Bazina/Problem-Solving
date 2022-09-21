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
const int MAXN = 2e5 + 7;
vector<ll> dp;
vector<int> monsters;
int m;

ll recur(int i) {
    if (i > m)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    ll ans1, ans2, ans;

    ans2 = recur(i + 1);
    ans1 = recur(i + 2) + monsters[i];

    dp[i] = ans = max(ans1, ans2);
    return ans;
}

ll iter() {
    dp[1] = monsters[1];

    for (int i = 2; i <= m; ++i) {
        ll p1 = dp[i - 1];
        ll p2 = dp[i - 2] + monsters[i];
        dp[i] = max(p1, p2);
    }

    return dp[m];
}

int main() {
    IOS
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> m;
        dp.clear(), monsters.clear();
        dp.resize(m + 1, 0), monsters.resize(m + 1);

        for (int j = 1; j <= m; ++j)
            cin >> monsters[j];

        cout << "Case " << i << ": " << iter() << "\n";
    }

    return 0;
}