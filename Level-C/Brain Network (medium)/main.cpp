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
vector<ll> dist;
vector<bool> vis;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
vector<vector<ll>> adj;

void dfs(ll v) {
    vis[v] = true;
    for (auto ch: adj[v]) {
        if (!vis[ch])
            dfs(ch);
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

            for (auto neighbour: adj[curr])
                if (!vis[neighbour])
                    dfs.push(neighbour);
        }
    }
}

void bfs(ll v) {
    queue<ll> bfs;
    dist[v] = 0;
    bfs.push(v);

    while (!bfs.empty()) {
        ll curr = bfs.front();
        bfs.pop();
        for (auto neighbour: adj[curr]) {
            if (dist[curr] + 1 < dist[neighbour]) {
                dist[neighbour] = dist[curr] + 1;
                bfs.push(neighbour);
            }
        }
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    dist.resize(n + 1, mod);

    for (ll i = 1; i <= m; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bfs(1);

    ll mx = 0, idx = 0;

    for (int i = 2; i <= n; ++i) {
        if (mx <= dist[i]) {
            mx = dist[i];
            idx = i;
        }
    }
    dist.clear(), dist.resize(n + 1, mod);
    bfs(idx);

    cout << *max_element(dist.begin() + 1, dist.end());
}

int main() {
    IOS
    solve();
    return 0;
}