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
ll MAXN = 1e6 + 5, mod = 1e9 + 7;
vector<ll> fact(MAXN, 1);
vector<bool> primes(MAXN, true);
vector<vector<ll>> primesDiv(MAXN);

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

void sieve() {
    // Sieve
    primes[0] = primes[1] = false;
    for (ll i = 2; i < MAXN; i += 1 + (i & 1))
        if (primes[i] && i * i < MAXN)
            for (ll j = i * i; j < MAXN; j += i)
                primes[j] = false;

    // Sieve and Divisors
    primes[0] = primes[1] = false;
    for (ll i = 2; i < MAXN; i += 1 + (i & 1))
        if (primes[i]) {
            primesDiv[i].push_back(i);
            for (ll j = i + i; j < MAXN; j += i) {
                primesDiv[j].push_back(i);
                primes[j] = false;
            }
        }
}

void factorial() {
    // Factorial
    for (ll i = 1; i < MAXN; ++i)
        fact[i] *= mul(fact[i - 1], i);
}

ll ncr(ll n, ll r) {
    ll m = mul(fact[n], fp(fact[n - r], mod - 2));
    m = mul(m, fp(fact[r], mod - 2));
    return m;
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}