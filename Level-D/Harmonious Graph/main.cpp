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

int n, m, l, r;
vector<bool> vis;
vector<pair<int, int>> segment;
vector<vector<int>> graph;

void solve(int src) {
    if (!vis[src]) vis[src] = true;
    else return;

    l = min(l, src);
    r = max(r, src);

    for (auto neighbour : graph[src]) {
        solve(neighbour);
    }
}

int main() {
    IOS
    graph.clear();
    vis.clear();
    int ans = 0;
    cin >> n >> m;

    graph.resize(n + 1);
    vis.resize(n + 1);

    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            l = i, r = i;
            solve(i);
            segment.push_back(mp(l, r));
        }
    }

    srt(segment);
    l = segment[0].first, r = segment[0].second;

    for (int i = 1; i < segment.size(); ++i) {
        if (segment[i].first >= l && segment[i].first <= r) {
            r = max(segment[i].second, r);
            ans++;
        } else {
            r = segment[i].second;
            l = segment[i].first;
        }
    }

    cout << ans << endl;

    return 0;
}