#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll price(ll mid, ll nb, int b, int c, int s, ll nc, ll ns, ll pb, ll pc, ll ps) {
    ll tb, tc, ts, total;
    tb = (mid * b - nb >= 0) ? mid * b - nb : 0;
    tc = (mid * c - nc >= 0) ? mid * c - nc : 0;
    ts = (mid * s - ns >= 0) ? mid * s - ns : 0;
    total = pb * tb + pc * tc + ps * ts;
    return total;
}

ll BS(int b, int c, int s, ll nb, ll nc, ll ns, ll pb, ll pc, ll ps, ll r) {
    // If the amount of money i will spend is less than what i have then
    // I have enough ingredients which i can use to make a sandwich
    ll lo = 0, hi = r + 100, count = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2, p = price(mid, nb, b, c, s, nc, ns, pb, pc, ps);
        if (p == r) return mid;
        else if (p > r) hi = mid - 1;
        else lo = mid + 1, count = mid;
    }
    return count;
}

int main() {
    IOS
    int b = 0, s = 0, c = 0;
    string x;
    cin >> x;
    for (char i : x) {
        if (i == 'B') b++;
        else if (i == 'C') c++;
        else if (i == 'S') s++;
    }
    ll nb, ns, nc, pb, ps, pc, r;
    cin >> nb >> ns >> nc;
    cin >> pb >> ps >> pc;
    cin >> r;
    ll count = BS(b, c, s, nb, nc, ns, pb, pc, ps, r);
    cout << count;
    return 0;
}