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

struct op {
    ll l, r, d;
};

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + 1), prefix(n + 2, 0), queries(m + 2, 0);
    vector<op> operations(m + 2);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= m; ++i)
        cin >> operations[i].l >> operations[i].r >> operations[i].d;

    for (int i = 1; i <= k; ++i) {
        int x, y;
        cin >> x >> y;
        queries[x]++;
        queries[y + 1]--;
    }

    for (int i = 1; i <= m; ++i) {
        queries[i] += queries[i - 1];
        prefix[operations[i].l] += operations[i].d * queries[i];
        prefix[operations[i].r + 1] -= operations[i].d * queries[i];
    }

    for (int i = 1; i <= n; ++i)
        prefix[i] += prefix[i - 1];

    for (int i = 1; i <= n; ++i)
        cout << a[i] + prefix[i] << " ";
}

int main() {
    IOS
    //int t;
    //cin >> t;
    //while (t--)
    solve();
    return 0;
}