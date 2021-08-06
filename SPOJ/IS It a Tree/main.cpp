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


vector<bool> vis;
vector<vector<int>> tree;

bool solve(int v) {
    stack<int> dfs;
    dfs.push(v);
    while (!dfs.empty()) {
        int curr = dfs.top();
        dfs.pop();
        if (!dfs.empty() && dfs.top() == curr) return false;
        vis[curr] = true;
        for (auto neighbour : tree[curr]) {
            if (!vis[neighbour]) dfs.push(neighbour);
        }
    }
    return true;
}

int main() {
    IOS
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0) {
        cout << "NO";
        return 0;
    }
    vis.resize(n + 1);
    tree.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    for (int i = 1; i < n + 1; ++i) {
        if (!vis[i]) {
            if (solve(i)) continue;
            else {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}