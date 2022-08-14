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
vector<vector<pair<ll, ll>>> adj;
vector<pair<ll, pair<ll, ll>>> ans;

void bfs(ll v) {
    ll e = 0;
    ll weight = LONG_LONG_MAX;
    queue<ll> bfs;
    dist[v] = 0;

    bfs.push(v);
    vis[v] = true;

    while (!bfs.empty()) {
        ll curr = bfs.front();
        bfs.pop();
        for (auto neighbour: adj[curr]) {
            if (!vis[neighbour.first]) {
                if (weight > neighbour.second)
                    weight = neighbour.second;

                if ((ll) adj[neighbour.first].size() == 0)
                    e = neighbour.first;

                vis[neighbour.first] = true;
                bfs.push(neighbour.first);
            }
        }
    }
    ans.push_back({v, {e, weight}});
}

void solve() {
    ll n, p;
    cin >> n >> p;
    vector<ll> in(n + 1, 0), out(n + 1, 0);

    vis.clear(), adj.clear(), dist.clear();
    vis.resize(n + 1), adj.resize(n + 1), dist.resize(n + 1, mod);

    for (ll i = 1; i <= p; ++i) {
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        out[x]++;
        in[y]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (out[i] > 0 && in[i] == 0)
            bfs(i);
    }

    srt(ans);
    cout << ans.size() << '\n';
    for (auto i: ans) {
        cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
    }
}

int main() {
    IOS
    solve();
    return 0;
}