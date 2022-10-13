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
int MAXN = 1e6 + 5, mod = 1e9 + 7;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n), ans(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    if (n == 1) {
        cout << "0\n";
        return;
    }
    if (n == 2 and a[0] <= a[1]) {
        cout << a[1] - a[0] << "\n";
        return;
    } else if (n == 2 and a[0] > a[1]) {
        cout << "-1\n";
        return;
    }

    int i = (n / 2) - 1, j = (int) ceil((double) n / 2);
    while (i >= 0) {
        if (a[i] > a[j]) {
            cout << "-1\n";
            return;
        } else if (a[i] < a[j]) {
            ans[i] = a[j] - a[i];
        }
        i--;
        j++;
    }

    reverse(ans.begin(), ans.end());
    if (is_sorted(ans.begin(), ans.end()))
        cout << ans[n - 1] << '\n';
    else
        cout << "-1\n";
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}