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
    ll n, tmp;
    cin >> n;
    tmp = n;

    if (n <= 3 || ((n & 1) != 0)) {
        cout << -1 << "\n";
        return;
    }

    ll cnt4 = 0, cnt6 = 0, mod4, mod6;

    while (n % 6 != 0) {
        n -= 4;
        cnt4++;
    }
    mod6 = n / 6;

    n = tmp;
    while (n % 4 != 0) {
        n -= 6;
        cnt6++;
    }
    mod4 = n / 4;

    cnt4 += mod6;
    cnt6 += mod4;
    if (cnt4 == 0 || cnt6 == 0) {
        cout << max(cnt4, cnt6) << " " << max(cnt4, cnt6) << "\n";
        return;
    } else {
        cout << cnt4 << " " << cnt6 << "\n";
    }
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}