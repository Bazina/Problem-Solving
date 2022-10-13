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
int mod = 1e9 + 7;
ll dp[17][33000];
int n, T;
pair<int, int> songs[17];

ll recur(int idx, int mask, int time) {
    if (time == T)
        return 1;

    if (time > T)
        return 0;

    ll &ans = dp[idx][mask];
    if (~ans)
        return ans % mod;
    ans = 0;

    for (int i = 1; i <= n; ++i) {
        if (((mask >> (i - 1)) & 1) || songs[i].second == songs[idx].second)
            continue;

        ans += recur(i, mask | (1 << (i - 1)), time + songs[i].first) % mod;
    }

    return ans % mod;
}

void solve() {
    cin >> n >> T;

    for (int i = 1; i <= n; ++i)
        cin >> songs[i].first >> songs[i].second;

    songs[0].first = songs[0].second = 0;
    memset(dp, -1, sizeof dp);

    cout << recur(0, 0, 0) << '\n';
}

int main() {
    IOS
    solve();
    return 0;
}