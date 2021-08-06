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
vector<int> covered;
vector<vector<int>> cities;
vector<pair<int, int>> sol;

void solve(int src, int dist) {
    vis.clear();
    vis.resize(cities.size());
    queue<pair<int, int>> bfs;
    bfs.push(mp(src, 0));
    vis[src] = true;
    covered[src]++;
    while (!bfs.empty() && dist > 0) {
        pair<int, int> curr = bfs.front();
        bfs.pop();
        if (curr.second >= dist) continue;
        for (int neighbour : cities[curr.first]) {
            if (!vis[neighbour]) {
                vis[neighbour] = true;
                bfs.push(mp(neighbour, curr.second + 1));
                covered[neighbour]++;
            }
        }
    }
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        covered.clear();
        sol.clear();
        cities.clear();
        bool flag = true;
        int n, m, r;
        cin >> n >> r >> m;
        cities.resize(n + 1);
        sol.resize(m);
        covered.resize(n + 1);

        for (int i = 0; i < r; ++i) {
            int x, y;
            cin >> x >> y;
            cities[x].push_back(y);
            cities[y].push_back(x);
        }
        for (int i = 0; i < m; ++i) {
            cin >> sol[i].first >> sol[i].second;
            solve(sol[i].first, sol[i].second);
        }

        for (int i = 1; i < n + 1; ++i) {
            if (covered[i] > 1 || covered[i] == 0) {
                cout << "No" << endl;
                flag = false;
                break;
            }
        }
        if (flag) cout << "Yes" << endl;
    }
    return 0;
}
