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
const int MAXN = 1e5 + 5;
ll freq[MAXN];
ll dp[MAXN];
int n;

ll recur(int i) {
    if (i > 1e5)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    ll take = freq[i] * i + recur(i + 2);
    ll leave = recur(i + 1);

    dp[i] = max(leave, take);
    return dp[i];
}

ll iter() {
    dp[1] = freq[1];

    for (int i = 2; i <= 1e5; ++i) {
        ll p1 = dp[i - 1];
        ll p2 = dp[i - 2] + freq[i] * i;

        dp[i] = max(p1, p2);
    }

    return dp[(int) 1e5];
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        freq[x]++;
    }
    memset(dp, 0, sizeof dp);
    cout << iter() << "\n";
}

int main() {
    IOS
    solve();
    return 0;
}