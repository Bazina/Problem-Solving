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
int MAXN = 1e6 + 5, mod = 1e6 + 7;
vector<int> dist, seq, idx, parent;
vector<bool> vis;
vector<vector<int>> adj;

void bfs(int v) {
    queue<int> bfs;
    dist[v] = 0;
    vis[v] = true;
    parent[v] = 1;

    bfs.push(v);

    while (!bfs.empty()) {
        int curr = bfs.front();
        bfs.pop();
        for (auto neighbour: adj[curr]) {
            if (dist[curr] + 1 < dist[neighbour] && !vis[neighbour]) {
                parent[neighbour] = curr;
                dist[neighbour] = dist[curr] + 1;
                vis[neighbour] = true;
                bfs.push(neighbour);
            }
        }
    }
}

void solve() {
    int n;
    bool valid = true;
    cin >> n;

    adj.resize(n + 1), dist.resize(n + 1, mod), vis.resize(n + 1);
    idx.resize(n + 1), seq.resize(n + 1), parent.resize(n + 1);

    for (int i = 1; i <= n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i) {
        cin >> seq[i];
        idx[seq[i]] = i;
    }

    bfs(1);
    for (int i = 2; i <= n; ++i) {
        if (dist[seq[i]] < dist[seq[i - 1]] || idx[parent[seq[i]]] < idx[parent[seq[i - 1]]]) {
            valid = false;
            break;
        }
    }

    if (valid)
        cout << "Yes";
    else
        cout << "No";
}

int main() {
    IOS

    solve();
    return 0;
}