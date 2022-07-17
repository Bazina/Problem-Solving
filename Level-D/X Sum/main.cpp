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
    int n, m, maxi = 0;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int sum = 0;
            for (int k = i, l = j; k < n && l < m; ++k, ++l) {
                sum += grid[k][l];
            }

            for (int k = i - 1, l = j - 1; k >= 0 && l >= 0; --k, --l) {
                sum += grid[k][l];
            }

            for (int k = i - 1, l = j + 1; k >= 0 && l < m; --k, ++l) {
                sum += grid[k][l];
            }

            for (int k = i + 1, l = j - 1; k < n && l >= 0; ++k, --l) {
                sum += grid[k][l];
            }

            maxi = max(maxi, sum);
        }
    }
    cout << maxi << "\n";
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}