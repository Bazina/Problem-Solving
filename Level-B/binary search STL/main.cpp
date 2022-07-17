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


int main() {
    IOS
    int n, q;
    cin >> n >> q;

    ll a[100001], tmp[100001];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= q; ++i) {
        string s;
        ll x;
        cin >> s >> x;

        if (s == "lower_bound") {
            auto y = lower_bound(a + 1, a + n + 1, x);
            if (y == a + n + 1)
                cout << "-1" << endl;
            else
                cout << a[y - a] << endl;
        } else if (s == "upper_bound") {
            auto y = upper_bound(a + 1, a + n + 1, x);
            if (y == a + n + 1)
                cout << "-1" << endl;
            else
                cout << a[y - a] << endl;
        } else {
            cout << (binary_search(a + 1, a + n + 1, x) ? "found" : "not found") << endl;
        }
    }
    return 0;
}