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
#define bsrch(a, n)    (binary_search(a.begin(), a.end() , n))
#define srt(a)     (sort(a.begin(), a.end()))
#define revsrt(a)     (sort(a.rbegin(), a.rend()))
#define rev(a)  (reverse(a.begin(), a.end()))
#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))
#define cnt(a, i)  (count(a.begin(), a.end(), i))
#define coutv(a)     for(int i=0; i<a.size(); i++){cout<<a[i] << " ";}
#define cinv(a)     for(int i = 0; i < a.size(); i++){cin >> a[i];}
#define cinvP1(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].first; }
#define cinvP2(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].second; }
#define isfind(a, s)  a.find(s) != a.npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b)    for(int i = a; i < b; i++)

ll check(vector<ll> trees, ll h) {
    ll woods = 0;
    for (int i = 0; i < trees.size(); ++i) {
        if (h < trees[i]) woods += trees[i] - h;
    }
    return woods;
}

ll BS(vector<ll> trees, ll lo, ll hi, ll m) {
    while (hi >= lo) {
        ll mid = (lo + hi) / 2;
        ll woods = check(trees, mid);
        if (woods < m) hi = mid - 1;   // Make it higher
        else if (woods > m) lo = mid + 1;
        else if (woods == m) return mid;
    }
    return hi;
}

int main() {
    IOS
    ll n, m;
    cin >> n >> m;
    vector<ll> trees(n);
    cinv(trees)
    srt(trees);
    ll height = BS(trees, trees[0], trees[trees.size() - 1], m);
    cout << height;
    return 0;
}