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
ld dp[33][256];
int n, m, p, a, b;
int tickets[10];
vector<pair<int, int>> road[33];

ld recur(int tickets_mask, int curr) {
    if (curr == b)
        return 0;
    if (tickets_mask == (1 << (2 * n)) - 1)
        return 1e18;

    ld &ans = dp[curr][tickets_mask];
    if (ans != 0)
        return ans;
    ans = 1e18;

    for (auto j: road[curr]) {
        int next = j.first;
        ld cost = j.second;

        for (int i = 1; i <= n; ++i) {
            if ((tickets_mask >> (i - 1)) & 1)
                continue;
            ans = min(ans, recur(tickets_mask | (1 << (i - 1)), next) + cost / tickets[i]);
        }
    }

    return ans;
}

void solve() {
    while (cin >> n && n != 0) {
        cin >> m >> p >> a >> b;

        for (int i = 0; i <= m; ++i)
            road[i].clear();

        for (int i = 1; i <= n; ++i)
            cin >> tickets[i];

        for (int i = 1; i <= p; ++i) {
            int x, y, c;
            cin >> x >> y >> c;
            road[x].emplace_back(y, c);
            road[y].emplace_back(x, c);
        }

        memset(dp, 0, sizeof dp);

        ld ans = recur(0, a);
        if (ans == 1e18)
            printf("Impossible\n");
        else
            printf("%.5Lf\n", ans);
    }
}

int main() {
    IOS
    solve();
    return 0;
}