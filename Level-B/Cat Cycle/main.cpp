#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define bsrch(a, n)    (binary_search(a.begin(), a.end(), n))
#define srt(a)     (sort(a.begin(), a.end()))
#define rev(a)  (reverse(a.begin(), a.end()))
#define sum(a)      (accumulate ((a).begin(), (a).end(), 0ll))
#define cnt(a,i)  (count(a.begin(), a.end(), i))
#define coutv(a)     for(int i = 0; i < a.size(); i++){ cout << a[i] << " "; }
#define cinv(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i]; }
#define IOS ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define rep(i, a, b)    for(int i = a; i < b; i++)
#define isfind(a, s)  a.find(s) != a.npos

void solve() {
    ll n, k, overlab = 0, pos;
    cin >> n >> k;
    if (n % 2 == 0){
        pos = k % n;
        if (pos == 0){
            pos = n;
        }
        cout << pos << "\n";
    } else {
        overlab = (k - 1) / (n / 2);
        pos = (k + overlab) % n;
        if (pos == 0){
            pos = n;
        }
        cout << pos << "\n";
    }
}

int main() {
    IOS
    ll t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
