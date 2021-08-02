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
#define MOD 1000000007

void solve() {
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> mono(n), poly(m), seq;
    cinv(mono)
    cinv(poly)
    int i = 0, j = 0;
    while (i < n || j < m) {
        int x , y;
        if (i < n) x = mono[i];
        else x = -1;
        if (j < m) y = poly[j];
        else y = -1;
        if (x >= 0 && x <= k) {
            seq.push_back(x);
            i++;
            if (x == 0) k++;
        } else if (y >= 0 && y <= k) {
            seq.push_back(y);
            j++;
            if (y == 0) k++;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    for (int l = 0; l < n + m; ++l) {
        cout << seq[l] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}