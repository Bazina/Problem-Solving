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

int n, m, cnt = 0;
vector<bool> vis;
vector<int> cat;
vector<pair<int, int>> deg;
vector<vector<int>> tree;

void solve(int src, int size) {
    if (!vis[src]) vis[src] = true;
    else return;
    if (size > m) return;
    if (deg[src].second == 1 && deg[src].first == 1 && src != 1) {
        if (size <= m) cnt++;
        return;
    }
    for (auto neighbour : tree[src]) {
        solve(neighbour, (cat[neighbour] > 0) ? size + cat[neighbour] : 0);
    }
}

int main() {
    IOS
    cat.clear();
    tree.clear();
    deg.clear();
    cin >> n >> m;
    tree.resize(n + 1);
    cat.resize(n + 1);
    deg.resize(n + 1);
    vis.resize(n + 1);

    for (int i = 1; i < n + 1; ++i) {
        cin >> cat[i];
    }

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
        deg[x].first++, deg[x].second++;
        deg[y].first++, deg[y].second++;
    }

    int start = 1;

    solve(start, cat[start]);
    cout << cnt << endl;

    return 0;
}