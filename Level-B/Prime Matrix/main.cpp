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
int MAXN = 2e5 + 25;
vector<ll> PRIMES;
vector<bool> primes(MAXN, true);

void sieve() {
    primes[0] = primes[1] = false;
    // Sieve
    for (ll i = 2; i < MAXN; i += 1 + (i & 1))
        if (primes[i]) {
            PRIMES.push_back(i);
            for (ll j = i * i; j < MAXN; j += i)
                primes[j] = false;
        }
}

void solve() {
    ll n, m, mn = INT_MAX;
    cin >> n >> m;
    sieve();
    vector<vector<ll>> c(n, vector<ll>(m));
    for (int i = 0; i < n; ++i) {
        ll costR = 0;
        for (int j = 0; j < m; ++j) {
            ll x;
            cin >> x;
            c[i][j] = *lower_bound(PRIMES.begin(), PRIMES.end(), x) - x;
            costR += c[i][j];
        }
        mn = min(mn, costR);
    }

    for (int i = 0; i < m; ++i) {
        ll costC = 0;
        for (int j = 0; j < n; ++j) {
            costC += c[j][i];
        }
        mn = min(mn, costC);
    }

    cout << mn;
}

int main() {
    IOS
    solve();
    return 0;
}