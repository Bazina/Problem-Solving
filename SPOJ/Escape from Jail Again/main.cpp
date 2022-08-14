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
int mod = 1e9 + 7;
int n, m, ans = mod;
vector<vector<vector<int>>> dist;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
enum prison {
    wall, door, open, close, empty
};
vector<vector<prison>> adj;

void bfs(int x, int y) {
    queue<pair<pair<int, int>, int>> bfs;
    bfs.push({{x, y}, 0});
    dist[x][y][0] = 0;

    while (!bfs.empty()) {
        int r = bfs.front().first.first, c = bfs.front().first.second, s = bfs.front().second;
        bfs.pop();

        if (r == n || r == 1 || c == 1 || c == m) {
            ans = dist[r][c][s];
            return;
        }

        for (int i = 0; i < 4; ++i) {
            int newR = r + dx[i], newC = c + dy[i], newS = s;

            if (newR > n || newR < 1 || newC < 1 || newC > m
                || (adj[newR][newC] == door && !newS) || adj[newR][newC] == wall)
                continue;

            if (adj[newR][newC] == open)
                newS = 1;
            else if (adj[newR][newC] == close)
                newS = 0;

            if (dist[newR][newC][newS] > dist[r][c][s] + 1) {
                dist[newR][newC][newS] = dist[r][c][s] + 1;
                bfs.push({{newR, newC}, newS});
            }
        }
    }
}

void solve() {
    while (cin >> n >> m && n != -1) {
        int x, y;
        ans = mod;
        adj.clear(), dist.clear();
        adj.resize(n + 1, vector<prison>(m + 1));
        dist.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(2, mod)));

        for (int i = 1; i <= n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                if (s[j] == 'W')
                    adj[i][j + 1] = wall;
                else if (s[j] == 'D')
                    adj[i][j + 1] = door;
                else if (s[j] == 'O')
                    adj[i][j + 1] = open;
                else if (s[j] == 'C')
                    adj[i][j + 1] = close;
                else if (s[j] == 'H') {
                    x = i, y = j + 1;
                    adj[i][j + 1] = empty;
                } else
                    adj[i][j + 1] = empty;
            }
        }
        bfs(x, y);

        if (ans == mod)
            cout << "-1\n";
        else
            cout << ans + 1 << '\n';
    }
}

int main() {
    IOS
    solve();
    return 0;
}