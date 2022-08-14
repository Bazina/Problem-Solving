#include <iostream>
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
ll MAXN = 1e6 + 9, mod = 1e9 + 7;
bool sex = false;
vector<bool> vis;
vector<ll> bi;
vector<vector<ll>> adj;

void dfs(ll v, ll p) {
    vis[v] = true;
    for (auto ch: adj[v]) {
        if (!vis[ch]) {
            bi[ch] = 1 - p;
            dfs(ch, bi[ch]);
        } else if (bi[v] == bi[ch])
            sex = true;
    }
}

void dfs2(ll v, ll p) {
    stack<pair<ll, ll>> dfs;
    dfs.push({v, p});
    while (!dfs.empty()) {
        ll curr = dfs.top().first;
        ll currBi = dfs.top().second;
        dfs.pop();

        if (!vis[curr]) {
            vis[curr] = true;

            for (auto neighbour: adj[curr])
                if (!vis[neighbour]) {
                    bi[neighbour] = 1 - currBi;
                    dfs.push({neighbour, bi[neighbour]});
                } else if (bi[neighbour] == bi[curr])
                    sex = true;
        }
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;

    sex = false;
    vis.clear();
    adj.clear();
    bi.clear();
    vis.resize(n + 1);
    adj.resize(n + 1);
    bi.resize(n + 1, 0);

    for (ll i = 1; i <= m; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) {
            bi[i] = 1;
            dfs2(i, 1);
        }
    }
    if (sex)
        cout << "Suspicious bugs found!\n";
    else
        cout << "No suspicious bugs found!\n";
}

int main() {
    IOS
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; ++i) {
        cout << "Scenario #" << i << ":\n";
        solve();
    }

    return 0;
}