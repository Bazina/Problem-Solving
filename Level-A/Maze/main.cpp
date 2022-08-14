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
ll MAXN = 1e6 + 5, mod = 1e9 + 7, n, m, k;
bool cyclic = false;
queue<pair<ll, ll>> nodes;
vector<vector<bool>> vis;
vector<pair<ll, ll>> path;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
vector<vector<char>> adj;

void dfs(ll x, ll y) {
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        ll newR = x + dx[i], newC = y + dy[i];
        if (newR > n || newR < 1 || newC < 1 || newC > m || adj[newR][newC] == '#' || vis[newR][newC])
            continue;
        dfs(newR, newC);
    }
    nodes.push({x, y});
}

void bfs(ll x, ll y) {
    queue<pair<ll, ll>> bfs;
    vis[x][y] = true;
    bfs.push({x, y});

    while (!bfs.empty()) {
        ll r = bfs.front().first, c = bfs.front().second;
        path.emplace_back(bfs.front());
        bfs.pop();
        for (int i = 0; i < 4; ++i) {
            ll newR = r + dx[i], newC = c + dy[i];
            if (newR > n || newR < 1 || newC < 1 || newC > m || adj[newR][newC] == '#' || vis[newR][newC])
                continue;
            bfs.push({newR, newC});
            vis[newR][newC] = true;
        }
    }
}

void solve() {
    ll r = 0, c = 0;
    cin >> n >> m >> k;

    adj.clear(), vis.clear();
    adj.resize(n + 1, vector<char>(m + 1)), vis.resize(n + 1, vector<bool>(m + 1));

    for (ll i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            adj[i][j + 1] = s[j];
            if (s[j] == '.' && !r)
                r = i, c = j;
        }
    }

    dfs(r, c);

    while (k--) {
        adj[nodes.front().first][nodes.front().second] = 'X';
        nodes.pop();
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cout << adj[i][j];
        cout << '\n';
    }
}

int main() {
    IOS
    solve();
    return 0;
}
