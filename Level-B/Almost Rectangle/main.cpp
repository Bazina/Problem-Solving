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
#define all(v)			((v).begin()), ((v).end())
#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define bsrch(a , n)    (binary_search(a.begin() , a.end() , n))
#define srt(a)     (sort(a.begin() , a.end()))
#define revsrt(a)     (sort(a.rbegin() , a.rend()))
#define rev(a)  (reverse(a.begin() , a.end()))
#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))
#define cnt(a,i)  (count(a.begin() , a.end() , i))
#define coutv(a)     for(int i=0; i<a.size() ; i++){cout<<a[i] << " ";}
#define cinv(a)     for(int i=0; i<a.size() ; i++){cin>>a[i];}
#define isfind(a,s)  a.find(s) != a.npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)

void solve() {
    int n, k = 0;
    cin >> n;
    char arr[n][n];
    vector<pair<int, int>> pos(2);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == '*') {
                pos[k].first = i;
                pos[k].second = j;
                k++;
            }
        }
    }
    if (pos[0].first != pos[1].first && pos[0].second != pos[1].second) {
        arr[pos[0].first][pos[1].second] = '*';
        arr[pos[1].first][pos[0].second] = '*';
    } else if (pos[0].first == pos[1].first && n - 1 != pos[0].first) {
        arr[pos[0].first + 1][pos[1].second] = '*';
        arr[pos[1].first + 1][pos[0].second] = '*';
    } else if (pos[0].first == pos[1].first && n - 1 == pos[0].first) {
        arr[pos[0].first - 1][pos[1].second] = '*';
        arr[pos[1].first - 1][pos[0].second] = '*';
    } else if (pos[0].second == pos[1].second && n - 1 != pos[0].second) {
        arr[pos[0].first][pos[1].second + 1] = '*';
        arr[pos[1].first][pos[0].second + 1] = '*';
    } else if (pos[0].second == pos[1].second && n - 1 == pos[0].second) {
        arr[pos[0].first][pos[1].second - 1] = '*';
        arr[pos[1].first][pos[0].second - 1] = '*';
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}

int main() {
    IOS
    ll t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}