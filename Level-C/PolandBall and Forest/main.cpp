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
ll l = 0;
vector<bool> vis;
vector<ll> level, a;
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
    bfs.push(v);
    vis[v] = true;
    level[v] = 1;
    while (!bfs.empty()) {
        ll curr = bfs.front();
        bfs.pop();
        for (auto neighbour: adj[curr]) {
            if (!vis[neighbour]) {
                vis[neighbour] = true;
                level[neighbour] = level[curr] + 1;
                a[l] = max(a[l], level[neighbour]);
                bfs.push(neighbour);
            }
        }
    }
}

void solve() {
    ll n, ans = 0;
    cin >> n;

    vis.resize(n + 1);
    adj.resize(n + 1);

    for (ll i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    for (ll i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ans++;
            dfs(i);
        }
    }

    cout << ans;
}

int main() {
    IOS
    solve();
    return 0;
}