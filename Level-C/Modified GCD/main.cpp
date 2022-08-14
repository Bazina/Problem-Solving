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

ll gcd(ll a, ll b, ll l, ll h) {
    vector<ll> v{a, b, h};
    ll result = *min_element(v.begin(), v.end());
    while (result > 0) {
        if (result >= l && a % result == 0 && b % result == 0)
            break;
        result--;
    }
    if (!result) return -1;
    return result;
}


vector<ll> factor(ll n) {
    vector<ll> v;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            v.push_back(i);
            if (n / i != i) v.push_back(n / i);
        }
    }

    return v;
}


void solve() {
    ll a, b, n;
    cin >> a >> b >> n;
    vector<ll> ap;
    vector<ll> c;
    ap = factor(a);
    srt(ap);
    for (long long &i: ap)
        if (b % i == 0)
            c.push_back(i);

    while (n--) {
        ll l, h, ans;
        cin >> l >> h;
        ans = *(upper_bound(c.begin(), c.end(), h) - 1);
        if (ans < l)
            ans = -1;
        cout << ans << '\n';
    }
}

int main() {
    IOS
    solve();
    return 0;
}