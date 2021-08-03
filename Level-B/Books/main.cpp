#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "cmath"

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
#define MOD 1000000007
#define EPS 1e-8

void solve() {
    ll n, t, cnt = 0, t_sum = 0, ans = 0;
    cin >> n >> t;
    vector<int> books(n);
    cinv(books)
    int i = 0, j = 0;
    while (i < books.size()) {
        while (j < books.size()) {
            if (t_sum + books[j] <= t) t_sum += books[j], cnt++, j++;
            else break;
        }
        t_sum -= books[i];
        ans = max(ans, cnt);
        i++, cnt--;
        if (j == books.size() - 1) break;
    }
    cout << ans << endl;
}

int main() {
    IOS
    solve();
    return 0;
}