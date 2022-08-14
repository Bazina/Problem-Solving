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
vector<bool> primes(1e6 + 5, true);


void solve() {
    ll d;
    cin >> d;

    vector<ll> ans;
    for (ll i = d + 1;; ++i) {
        if (primes[i]) {
            ans.push_back(i);
            break;
        }
    }

    for (ll i = ans.back() + d;; ++i) {
        if (primes[i]) {
            ans.push_back(i);
            break;
        }
    }

    cout << min(ans[0] * ans[1] * 1ll, 1ll * ans[0] * ans[0] * ans[0]) << "\n";
}

int main() {
    IOS
    primes[0] = primes[1] = false;
    for (ll i = 2; i < MAXN; i += 1 + (i & 1))
        if (primes[i] && i * i < MAXN)
            for (ll j = i * i; j < MAXN; j += i)
                primes[j] = false;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}