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

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n + 1, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x] = i;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x] = i;
    }

    n *= 2;
    int swap = n, swapB = n;
    // even number from the end will be always bigger than odd one
    // 1 3 5
    // 2 4 6
    // 2 bigger than 1, 4 bigger than 3 and so on
    for (int i = n; i > 0; i -= 2) {
        swapB = min(a[i], swapB);
        swap = min(a[i - 1] + swapB, swap);
    }

    cout << swap << '\n';
}

int main() {
    IOS
    int q;
    cin >> q;
    while (q--) solve();
    return 0;
}