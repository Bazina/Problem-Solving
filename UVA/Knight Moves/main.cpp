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
string src, dest;
vector<vector<ll>> dist;

void bfs(ll x, ll y) {
    vector<ll> dx{2, 1, -1, 2, -1, -2, 1, -2}, dy{1, 2, 2, -1, -2, -1, -2, 1};
    dist.clear();
    dist.resize(8, vector<ll>(8, mod));
    dist[x][y] = 0;
    queue<pair<ll, ll>> bfs;

    bfs.emplace(x, y);
    while (!bfs.empty()) {
        ll r = bfs.front().first, c = bfs.front().second;
        bfs.pop();
        for (int i = 0; i < 8; ++i) {
            ll newR = r + dx[i], newC = c + dy[i];
            if (newR < 0 || newR > 7 || newC > 7 || newC < 0)
                continue;
            if (dist[newR][newC] > dist[r][c] + 1) {
                dist[newR][newC] = dist[r][c] + 1;
                bfs.emplace(newR, newC);
            }
        }
    }
}

void solve() {
    while (cin >> src >> dest) {
        ll colS = src[0] - 'a', rowS = src[1] - '1';
        ll colD = dest[0] - 'a', rowD = dest[1] - '1';
        bfs(rowS, colS);
        cout << "To get from " << src << " to " << dest << " takes " << dist[rowD][colD] << " knight moves.\n";
    }
}

int main() {
    IOS
    solve();
    return 0;
}