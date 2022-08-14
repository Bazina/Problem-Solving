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

vector<bool> vis;
vector<vector<pair<int, int>>> adj;
vector<int> repair;

void dfs(int v, int p) {
    vis[v] = true;
    if (repair[v]) {
        repair[p] = 0;
        p = v;
    }
    for (auto ch: adj[v]) {
        if (!vis[ch.first]) {
            vis[ch.first] = true;
            dfs(ch.first, p);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vis.clear(), adj.clear();
    vis.resize(n + 1), adj.resize(n + 1), repair.resize(n + 1);

    for (int i = 1; i <= n - 1; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        adj[x].push_back({y, t});
        adj[y].push_back({x, t});
        if (t == 2)
            repair[x] = repair[y] = 1;
    }

    dfs(1, 1);

    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (repair[i])
            ans.push_back(i);
    }

    cout << ans.size() << '\n';
    coutv(ans)
}

int main() {
    IOS
    solve();
    return 0;
}