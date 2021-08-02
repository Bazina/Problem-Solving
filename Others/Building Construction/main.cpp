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
#define bsrch(a, n)    (binary_search(a.begin(), a.end() , n))
#define srt(a)     (sort(a.begin(), a.end()))
#define revsrt(a)     (sort(a.rbegin(), a.rend()))
#define rev(a)  (reverse(a.begin(), a.end()))
#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))
#define cnt(a, i)  (count(a.begin(), a.end(), i))
#define coutv(a)     for(int i=0; i<a.size(); i++){cout<<a[i] << " ";}
#define cinv(a)     for(int i = 0; i < a.size(); i++){cin >> a[i];}
#define cinvP1(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].first; }
#define cinvP2(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].second; }
#define isfind(a, s)  a.find(s) != a.npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b)    for(int i = a; i < b; i++)
#define MOD 1000000007

ll cost(double floor, const vector<pair<int, int>>& build) {
    ll cost = 0;
    for (auto & i : build) {
        cost += (fabs(floor - i.first) * i.second);
    }
    return cost;
}

void solve() {
    int n, mx = 0;
    cin >> n;
    vector<pair<int, int>> build(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x > mx) mx = x;
        build[i].first = x;
    }
    for (int i = 0; i < n; ++i) {
        int y;
        cin >> y;
        build[i].second = y;
    }
    double lo = 0.0, hi = mx, eps = 1e-1;
    while (hi - lo > eps) {
        double part = (hi - lo) / 3.0;
        double mid1 = lo + part, mid2 = hi - part;
        ll cost1 = cost(mid1, build);
        ll cost2 = cost(mid2, build);
        if (cost1 > cost2) lo = mid1;
        else hi = mid2;
    }
    int fl = floor(lo), cl = ceil(lo);
    cout << min(cost(fl, build), cost(cl, build)) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}