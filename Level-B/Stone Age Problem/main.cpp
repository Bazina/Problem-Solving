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
const int MAX = 2e5 + 10;

int a[MAX], tmp[MAX];


int main() {
    IOS;
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    long long ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += a[i];
    int last = -1, lastVal = 0;
    for (int i = 1; i <= q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int idx, x;
            cin >> idx >> x;
            if (tmp[idx] < last)
                ans -= lastVal;
            else
                ans -= a[idx];
            ans += x, a[idx] = x, tmp[idx] = i;
        } else if (t == 2) {
            int x;
            cin >> x;
            ans = 1ll * x * n;
            last = i, lastVal = x;
        }
        cout << ans << "\n";
    }
    return 0;
}