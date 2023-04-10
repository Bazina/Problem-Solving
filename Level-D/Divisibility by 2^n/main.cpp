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
ll MAXN = 1e6 + 5, mod = 1e9 + 7, twos = 0;

ll mul(ll x, ll y) {
    return ((x % mod) * (y % mod)) % mod;
}

ll add(ll x, ll y) {
    return ((((x % mod) + (y % mod)) % mod) + mod) % mod;
}

ll fp(ll base, ll power) {
    if (power == 0)
        return 1;
    if (power & 1)
        return (1ll * base * fp(base, power - 1)) % mod;
    ll res = fp(base, power >> 1);
    return 1ll * res * res % mod;
}

void divisors(ll n) {
    while (n % 2 == 0) {
        twos++;
        n /= 2;
    }
}

void solve() {
    ll n, ans = 0;
    twos = 0;
    cin >> n;

    vector<ll> a(n + 1), div;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        divisors(a[i]);
    }

    for (int i = 2; i <= n; i += 2) {
        int x = 0;
        int temp = i;
        while (temp % 2 == 0) {
            x++;
            temp /= 2;
        }
        div.push_back(x);
    }
    revsrt(div);

    for (long long j : div) {
        if (twos >= n)
            break;
        twos += j;
        ans++;
    }

    if (twos >= n) {
        cout << ans << '\n';
    }
    else cout << "-1\n";
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}