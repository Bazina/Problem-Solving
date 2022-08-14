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
ll MAXN = 1e6 + 5;
vector<bool> primes;
vector<ll> PRIMES;


void sieve(ll n) {
    primes.resize(n + 1, true);
    // Sieve
    primes[0] = primes[1] = false;
    for (ll i = 2; i < n + 1; i += 1 + (i & 1))
        if (primes[i]) {
            PRIMES.push_back(i);
            for (ll j = i * i; j < n + 1; j += i)
                primes[j] = false;
        }
}

void solve() {
    ll n, k, ans = 0, x;
    cin >> n >> k;
    sieve(n);

    for (int i = 0; i < PRIMES.size() - 1; ++i) {
        x = PRIMES[i] + PRIMES[i + 1] + 1;
        if (binary_search(PRIMES.begin(), PRIMES.end(), x))
            ans++;
    }

    cout << ((ans >= k) ? "YES" : "NO");
}

int main() {
    IOS
    solve();
    return 0;
}