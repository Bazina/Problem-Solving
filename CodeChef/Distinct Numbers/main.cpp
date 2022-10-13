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
    int n, k, ans1 = 0, ans2 = 0;
    cin >> n >> k;
    vector<int> a(n);
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s.insert(a[i]);
    }
    int mx = *max_element(a.begin(), a.end());

    int temp = k;
    for (int i = 1; i <= 2 * n && temp > 0; ++i) {
        if (s.find(i) != s.end())
            continue;
        else {
            ans2 += max(mx - i, 0);
            temp--;
        }
    }

    temp = k;
    if (mx == 2 * n)
        temp = 1;
    for (int i = 1; i <= 2 * n && temp > 0; ++i) {
        if (s.find(i) != s.end())
            continue;
        else {
            ans1 += max(2 * n - i, 0);
            temp--;
        }
    }


    cout << max(ans1, ans2) << '\n';
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}