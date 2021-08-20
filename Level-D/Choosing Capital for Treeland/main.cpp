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
#define cinv(a)     for(int i = 1; i < a.size(); i++){cin >> a[i];}
#define cinvP1(a)     for(int i = 1; i < a.size(); i++){ cin >> a[i].first; }
#define cinvP2(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].second; }
#define isfind(a, s)  a.find(s) != a.npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b)    for(int i = a; i < b; i++)

vector<bool> vis;
vector<vector<pair<int, int>>> cities;
vector<int> dp;

void dfs1(int src) {
    vis[src] = true;

    for (auto neighbour : cities[src]) {
        if (vis[neighbour.first]) continue;
        dfs1(neighbour.first);
        dp[1] += neighbour.second;
    }
}

void dfs2(int src) {
    vis[src] = true;

    for (auto neighbour : cities[src]) {
        if (vis[neighbour.first]) continue;

        /*
         * the number of edge to be reversed is the same for the parent node,
         * but we take into consideration the edge between the parent and child
         * if the edge between from the first to the second node (neighbour),
         * then for the neighbour this edge should be reversed
         * else it is ok and should be subtracted from the dp of parent
         */

        if (neighbour.second == 0) dp[neighbour.first] = dp[src] + 1;
        else dp[neighbour.first] = dp[src] - 1;
        dfs2(neighbour.first);
    }
}

int main() {
    IOS
    cities.clear();

    int n;
    cin >> n;

    cities.resize(n + 1);
    dp.resize(n + 1);
    vis.resize(n + 1);
    dp.assign(dp.size(), 0);

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        cities[x].emplace_back(y, 0);
        cities[y].emplace_back(x, 1);
    }

    // to get the number of edges to be reversed for city 1
    dfs1(1);
    vis.assign(vis.size(), false);
    // then here by dp, calc number of edges to be reversed for the rest of the cities
    dfs2(1);


    int mini = 1e9;
    for (int i = 1; i < dp.size(); ++i) {
        if (dp[i] < mini) mini = dp[i];
    }

    cout << mini << endl;
    for (int i = 1; i < dp.size(); ++i) {
        if (dp[i] == mini) cout << i << " ";
    }

    return 0;
}
