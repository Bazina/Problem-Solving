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

bool comp(ll a, ll b) {
    return abs(a) > abs(b);
}

vector<ll> a;

void solve() {
    ll n, m = 1;
    bool f = false;
    cin >> n;
    a.clear();
    a.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] >= 0)
            f = true;
    }
    sort(a.begin(), a.end(), comp);

    if (!f) {
        srt(a);
        cout << a[n - 5] * a[n - 4] * a[n - 3] * a[n - 2] * a[n - 1] << "\n";
    } else {
        for (int i = 0; i < 5; ++i)
            m *= a[i];

        for (int i = 5; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                ll tmp = a[i];
                for (int k = 0; k < 5; k++)
                    if (k != j)
                        tmp *= a[k];
                m = max(m, tmp);
            }
        }
        cout << m << "\n";
    }
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}