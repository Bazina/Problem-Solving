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

typedef struct end_points {
    ll x1, x2;
} end_points;


void solve() {
    ll n, h, gaps = 0;
    cin >> n >> h;
    vector<end_points> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].x1 >> a[i].x2;

    ll sum = a[0].x2 - a[0].x1, maxi = sum;
    for (int i = 0, j = 1; j < n;) {
        auto prev_seg = a[j - 1], seg = a[j];
        if (i == j) {
            sum = seg.x2 - seg.x1;
            gaps = 0;
            j++;
        } else if (gaps + seg.x1 - prev_seg.x2 < h) {
            sum += seg.x2 - seg.x1;
            gaps += seg.x1 - prev_seg.x2;
            j++;
        } else {
            sum -= a[i].x2 - a[i].x1;
            if (sum > 0)
                gaps -= a[i + 1].x1 - a[i].x2;
            i++;
        }
        maxi = max(sum, maxi);
    }
    cout << maxi + h;
}

int main() {
    IOS
    solve();
    return 0;
}