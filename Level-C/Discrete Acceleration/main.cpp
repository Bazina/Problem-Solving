#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

void solve() {
    ll n, l;
    cin >> n >> l;
    vector<ll> flags(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> flags[i];
    }
    flags[n + 1] = l, flags[0] = 0;
    ld rt = l, lt = 0, t;
    int it = 200;
    while (it--) {
        ld mid = (rt + lt) / 2, nx1 = l, nx2 = 0;
        t = mid;
        // after every flag the speed increases by 1
        for (int i = 1; i < n + 2; ++i) {
            ld curr = 1.0L * (flags[i] - flags[i - 1]) / i;
            if (curr >= t) {
                nx1 = flags[i - 1] + 1.0L * i * t;
                break;
            }
            else t -= curr;
        }
        t = mid;
        for (int i = n; i >= 0; --i) {
            ld curr = 1.0L * (flags[i + 1] - flags[i]) / (n - i + 1);
            if (curr >= t) {
                nx2 = flags[i + 1] - 1.0L * (n - i + 1) * t;
                break;
            }
            else t -= curr;
        }
        if (nx1 >= nx2) rt = mid;
        else lt = mid;
    }
    ld mid = (lt + rt) / 2;
    cout << fixed << setprecision(18) <<  mid << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}