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

int main() {
    IOS
    ll n, k, size = 0, i = 0, m = 0;
    cin >> n >> k;
    set<ll> multi;
    vector<int> index(n, 0);
    vector<bool> multiple(n, false);
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        multi.insert(x);
    }
    for (auto it : multi) {
        index[m] = it;
        m++;
    }
    for (auto it : multi) {
        if (!multiple[i]) {
            size++;
            ll x = it * k;
            ll y = binary_search(index.begin(), index.end(), x);
            if (y){
                ll ind = lower_bound(index.begin(), index.end(), x) - index.begin();
                multiple[ind] = true;
            }
        }
        i++;
    }
    cout << size;
    return 0;
}