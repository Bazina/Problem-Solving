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
int n, m, k;
vector<vector<int>> adj, dist;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
queue<pair<int, int>> bfsQ;

void bfs() {
    while (!bfsQ.empty()) {
        int r = bfsQ.front().first, c = bfsQ.front().second;
        bfsQ.pop();
        for (int i = 0; i < 4; ++i) {
            ll newR = r + dx[i], newC = c + dy[i];
            if (newR > n || newR < 1 || newC < 1 || newC > m)
                continue;
            if (dist[newR][newC] > dist[r][c] + 1) {
                dist[newR][newC] = dist[r][c] + 1;
                bfsQ.push({newR, newC});
            }
        }
    }
}

void solve() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> k;
    vector<pair<int, int>> a;

    adj.clear();
    adj.resize(n + 1, vector<int>(m + 1, 0));
    dist.resize(n + 1, vector<int>(m + 1, 1e9));

    for (int i = 1; i <= k; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x][y] = 1;
        a.emplace_back(x, y);
    }

    for (auto &i: a) {
        dist[i.first][i.second] = 0;
        bfsQ.push({i.first, i.second});
    }
    bfs();

    int ans = 0, x = 1, y = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (dist[i][j] > ans) {
                x = i, y = j;
                ans = dist[i][j];
            }
        }
    }

    cout << x << " " << y;
}

int main() {
    IOS
    solve();
    return 0;
}