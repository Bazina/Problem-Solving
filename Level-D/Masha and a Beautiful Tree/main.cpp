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
int n, ans = 0;
vector<int> a;

int combine(int l, int r, int m) {
    if (ans == -1)
        return -1;

    if (is_sorted(a.begin() + l, a.begin() + r + 1))
        return 0;
    else {
        if (is_sorted(a.begin() + l, a.begin() + m + 1) &&
            is_sorted(a.begin() + m + 1, a.begin() + r + 1)) {
            int k = 1;
            for (int i = l; i <= m; ++i)
                swap(a[i], a[m + k++]);

            ans++;

            if (is_sorted(a.begin() + l, a.begin() + r + 1))
                return 0;
            else
                return ans = -1;
        } else
            return ans = -1;
    }
}

int divide_conquer(int l, int r) {
    if (l >= r)
        return 0;
    int mid = (l + r) / 2;
    divide_conquer(mid + 1, r);
    divide_conquer(l, mid);
    return combine(l, r, mid);
}

void solve() {
    ans = 0;
    cin >> n;
    a.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    if (divide_conquer(0, n - 1) == 0)
        cout << ans << "\n";
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