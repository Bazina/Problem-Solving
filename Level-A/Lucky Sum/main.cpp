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
vector<ll> lucky;
ll sum = 0;

void solve(ll x, ll r) {
    if (x > r * 10) return;
    lucky.pb(x);
    solve(10 * x + 7, r);
    solve(10 * x + 4, r);
}

void calc(ll l, ll r, ll luckyNumber) {
    if (luckyNumber >= r) {
        sum += luckyNumber * (r - l + 1);
        return;
    }
    if (luckyNumber >= l) {
        sum += luckyNumber * (luckyNumber - l + 1);
        calc(luckyNumber + 1, r, *lower_bound(lucky.begin(), lucky.end(), luckyNumber + 1));
    }
}

int main() {
    IOS
    ll l, r;
    cin >> l >> r;

    solve(4, r);
    solve(7, r);
    srt(lucky);

    calc(l, r, *lower_bound(lucky.begin(), lucky.end(), l));

    cout << sum;
    return 0;
}