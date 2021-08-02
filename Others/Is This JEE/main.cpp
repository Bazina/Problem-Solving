#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "cmath"

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
#define MOD 10000000007
#define EPS 1e-8

double calc(double b, double c, double mid) {
    return (mid * mid + b * mid + c) / sin(mid);
}

void solve() {
    double b, c;
    cin >> b >> c;
    double lo = 0, hi = M_PI_2, mid1, mid2;
    double x1, x2;
    while (hi - lo > EPS) {
        double part = (hi - lo) / 3;
        mid1 = part + lo, mid2 = hi - part;
        x1 = calc(b, c, mid1);
        x2 = calc(b, c, mid2);
        if (x1 > x2) lo = mid1;
        else hi = mid2;
    }
    cout << fixed << setprecision(10) << calc(b, c, lo) << endl;
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}