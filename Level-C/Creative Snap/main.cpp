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

ll n, k, A, B;
vector<ll> a;

ll cost(ll l, ll r) {
    ll numAvengers = upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);

    if (!numAvengers)
        return A;

    ll currentCost = B * numAvengers * (r - l + 1);
    if (l != r) {
        ll mid = (l + r) / 2;
        ll left = cost(l, mid);
        ll right = cost(mid + 1, r);
        currentCost = min(currentCost, left + right);
    }

    return currentCost;
}

void solve() {
    cin >> n >> k >> A >> B;
    ll base = 1 << n;
    a.clear();
    a.resize(k);

    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    srt(a);
    cout << cost(1, base);
}

int main() {
    IOS
    //int t;
    //cin >> t;
    //while (t--)
    solve();
    return 0;
}