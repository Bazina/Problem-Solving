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


void solve() {
    int n, m, k, ans = 0, ast = 0;
    cin >> n >> m >> k;
    vector<vector<char>> a(n, vector<char>(m));
    vector<pair<pair<int, int>, int>> p;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == '*') ast++;
        }

    for (int l = 0; l < m; l++) {
        int d = -1;
        pair<int, int> point = {-1, -1};
        if (a[0][l] == '*') {
            d++;
            point = {0, l};
        } else
            d = -1;

        int i = 1;
        int j = l - 1;

        while (!(i < 0 || i >= n || j >= m || j < 0)) {
            if (a[i][j] == '*') {
                d++;
                point = {i, j};
            } else
                d = -1;
            i++;
            j--;
            if (d >= k)
                p.emplace_back(point, d);
        }
    }

    for (int l = 1; l < n; l++) {
        int d = -1;
        pair<int, int> point = {-1, -1};
        if (a[l][m - 1] == '*') {
            d++;
            point = {l, m - 1};
        } else
            d = -1;
        int i = l + 1;
        int j = m - 2;

        while (!(i < 0 || i >= n || j >= m || j < 0)) {
            if (a[i][j] == '*') {
                d++;
                point = {i, j};
            } else
                d = -1;
            i++;
            j--;
            if (d >= k)
                p.emplace_back(point, d);
        }
    }

    for (int l = n - 1; l >= 0; l--) {
        int d = -1;
        pair<int, int> point = {-1, -1};
        if (a[l][0] == '*') {
            d++;
            point = {l, 0};
        } else
            d = -1;
        int i = l + 1;
        int j = 1;

        while (!(i < 0 || i >= n || j >= m || j < 0)) {
            if (a[i][j] == '*') {
                d++;
                point = {i, j};
            } else
                d = -1;
            i++;
            j++;
            if (d >= k)
                p.emplace_back(point, d);
        }
    }

    for (int l = 1; l < m; l++) {
        int d = -1;
        pair<int, int> point = {-1, -1};
        if (a[0][l] == '*') {
            d++;
            point = {0, l};
        } else
            d = -1;
        int i = 1;
        int j = l + 1;

        while (!(i < 0 || i >= n || j >= m || j < 0)) {
            if (a[i][j] == '*') {
                d++;
                point = {i, j};
            } else
                d = -1;
            i++;
            j++;
            if (d >= k)
                p.emplace_back(point, d);
        }
    }

    srt(p);
    for (int i = 1; i < p.size(); ++i) {
        if (p[i].first.first == p[i - 1].first.first && p[i].first.second == p[i - 1].first.second) {
            int d = min(p[i].second, p[i - 1].second);
            if (a[p[i].first.first][p[i].first.second] != '1') {
                ans++;
                a[p[i].first.first][p[i].first.second] = '1';
            }

            int x = p[i].first.first, y = p[i].first.second;
            while (d > 0) {
                x--, y++, d--;
                if (a[x][y] != '1') {
                    ans++;
                    a[x][y] = '1';
                }
            }

            x = p[i].first.first, y = p[i].first.second, d = min(p[i].second, p[i - 1].second);
            while (d > 0) {
                x--, y--, d--;
                if (a[x][y] != '1') {
                    ans++;
                    a[x][y] = '1';
                }
            }

        }
    }

    if (ans >= ast) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}