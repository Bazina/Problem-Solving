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
#define bsrch(a, n)    (binary_search(a.begin(), a.end() , n))
#define srt(a)     (sort(a.begin(), a.end()))
#define revsrt(a)     (sort(a.rbegin(), a.rend()))
#define rev(a)  (reverse(a.begin(), a.end()))
#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))
#define cnt(a, i)  (count(a.begin(), a.end(), i))
#define coutv(a)     for(int i=0; i<a.size(); i++){cout<<a[i] << " ";}
#define cinv(a)     for(int i = 0; i < a.size(); i++){cin >> a[i];}
#define cinvP1(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].first; }
#define cinvP2(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].second; }
#define isfind(a, s)  a.find(s) != a.npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b)    for(int i = a; i < b; i++)
vector<vector<bool>> vis;
vector<vector<int>> paint;
map<int, int> color;

void solve(int v, int d, int c) {
    if (d < 0) return;
    if (vis[v][d]) return;
    if (color[v] == 0) color[v] = c;
    vis[v][d] = true;
    for (auto i : paint[v]) {
        solve(i, d - 1, c);
    }
}

int main() {
    IOS
    int n, m, q;
    cin >> n >> m;
    vis.resize(n + 1, vector<bool>(11, false));
    paint.resize(n + 1, vector<int>(0));
    for (int i = 1; i <= n; ++i) {
        color[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        paint[x].push_back(y);
        paint[y].push_back(x);
    }
    cin >> q;
    int que[q][3];
    for (int i = 0; i < q; ++i) {
        int v, d, c;
        cin >> v >> d >> c;
        que[i][0] = v, que[i][1] = d, que[i][2] = c;
    }
    for (int i = q - 1; i >= 0; --i) {
        solve(que[i][0], que[i][1], que[i][2]);
    }
    for (auto it : color) {
        cout << it.second << endl;
    }
    return 0;
}