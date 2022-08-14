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
ll MAXN = 1e6 + 5, mod = 1e9 + 7;
bool cyclic = false;
ll ans = 0, cnt = 0;
vector<bool> vis;
vector<vector<ll>> adj;

void dfs(ll v) {
    vis[v] = true;
    for (auto ch: adj[v]) {
        if (!vis[ch])
            cnt++, dfs(ch);
    }
}

void dfs2(ll v) {
    stack<ll> dfs;
    dfs.push(v);
    while (!dfs.empty()) {
        ll curr = dfs.top();
        dfs.pop();

        if (!vis[curr]) {
            vis[curr] = true;
            cnt++;

            for (auto neighbour: adj[curr])
                if (!vis[neighbour])
                    dfs.push(neighbour);
        }
    }
}

void solve() {
    ll c, r;
    while (cin >> c >> r && c) {
        map<string, ll> m;

        ans = 0, cnt = 0;
        vis.clear(), adj.clear();
        vis.resize(c + 1), adj.resize(c + 1);

        for (int i = 1; i <= c; ++i) {
            string s;
            cin >> s;
            m[s] = i;
        }

        for (ll i = 1; i <= r; ++i) {
            string x, y;
            cin >> x >> y;
            adj[m[y]].push_back(m[x]);
            adj[m[x]].push_back(m[y]);
        }

        for (ll i = 1; i <= c; ++i) {
            if (!vis[i]) {
                cnt = 0;
                dfs2(i);
                ans = max(ans, cnt);
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    IOS
    solve();
    return 0;
}