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

ll n;
vector<ll> a, c;


void solve() {
    cin >> n;
    a.clear();
    a.resize(n);
    c.resize(n);

    cinv(a)
    srt(a);

    ll r = n - 1, ans = 0;
    if (n & 1) {
        for (int i = 0; i < n; i += 2)
            c[i] = a[r--];
        for (int i = 1; i < n; i += 2)
            c[i] = a[r--];
    } else {
        for (int i = 1; i < n; i += 2)
            c[i] = a[r--];
        for (int i = 0; i < n; i += 2)
            c[i] = a[r--];
    }

    for (int i = 1; i < n - 1; ++i)
        if (c[i - 1] > c[i] && c[i + 1] > c[i])
            ans++;

    cout << ans << "\n";
    coutv(c)
}

int main() {
    IOS
    //int t;
    //cin >> t;
    //while (t--)
    solve();
    return 0;
}