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


void solve() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char> (n, '1'));
    vector<pair<char, int>> wins(n);
    string x;
    cin >> x;
    for (int i = 0; i < n; ++i) {
        wins[i].first = x[i];
        wins[i].second = 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) grid[i][j] = 'X';
            else if (grid[j][i] != '1') {
                if (grid[j][i] == '+') grid[i][j] = '-';
                else if (grid[j][i] == '-') grid[i][j] = '+';
                else grid[i][j] = '=';
            } else {
                if (x[i] == '1' && x[j] == '2') {
                    grid[i][j] = '+';
                    wins[i].second++;
                }
                else if (x[i] == '2' && x[j] == '1') {
                    grid[i][j] = '-';
                    wins[j].second++;
                }
                else if (x[i] == '2' && x[j] == '2') {
                    if (wins[i].second == 0) {
                        wins[i].second++;
                        grid[i][j] = '+';
                    }
                    else {
                        wins[j].second++;
                        grid[i][j] = '-';
                    }
                }
                else if (x[i] == '1' && x[j] == '1') grid[i][j] = '=';
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (wins[i].second == 0 && wins[i].first == '2') {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
