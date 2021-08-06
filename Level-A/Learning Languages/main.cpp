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
vector<vector<int>> lang;

bool dfs(int src) {
    if (vis[src]) return false;
    vis[src] = true;

    for (auto emp : lang[src]) {
        dfs(emp);
    }
    return true;
}

int main() {
    IOS
    int n, m, cnt = 0, zero = 0;
    cin >> n >> m;
    lang.resize(n + m + 1);
    vis.resize(n + m + 1);

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        for (int j = 1; j <= x; ++j) {
            int y;
            cin >> y;
            lang[i].push_back(y + n);
            lang[y + n].push_back(i);
        }
    }

    for (int i = 1; i <= lang.size(); ++i) {
        if (lang[i].empty()) zero++;
    }

    if (zero == n + m) {
        cout << n;
    } else {
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                if (dfs(i)) cnt++;
            }
        }
        cout << cnt - 1;
    }
    return 0;
}
