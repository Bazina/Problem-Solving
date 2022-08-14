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
ll MAXN = 1e6 + 5, mod = 1e9 + 7, n, m;
vector<ll> dist;

void bfs(ll v) {
    queue<ll> bfs;
    dist.resize(10100, 1e9);
    dist[v] = 0;

    bfs.push(v);
    while (!bfs.empty()) {
        ll curr = bfs.front();
        bfs.pop();
        ll child1 = curr - 1;
        ll child2 = curr * 2;
        if (child1 > 0 && dist[child1] > dist[curr] + 1) {
            dist[child1] = dist[curr] + 1;
            bfs.push(child1);
        }
        if (child2 < 10001 && dist[child2] > dist[curr] + 1) {
            dist[child2] = dist[curr] + 1;
            bfs.push(child2);
        }
    }
}

void solve() {
    cin >> n >> m;
    bfs(n);
    cout << dist[m];
}

int main() {
    IOS
    solve();
    return 0;
}