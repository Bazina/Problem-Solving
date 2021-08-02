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
#define all(v)			((v).begin()), ((v).end())
#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define bsrch(a , n)    (binary_search(a.begin() , a.end() , n))
#define srt(a)     (sort(a.begin() , a.end()))
#define revsrt(a)     (sort(a.rbegin() , a.rend()))
#define rev(a)  (reverse(a.begin() , a.end()))
#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))
#define cnt(a,i)  (count(a.begin() , a.end() , i))
#define coutv(a)     for(int i=0; i<a.size() ; i++){cout<<a[i] << " ";}
#define cinv(a)     for(int i=0; i<a.size() ; i++){cin>>a[i];}
#define isfind(a,s)  a.find(s) != a.npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)

void solve() {
    ll n, m, i = 0, counter = 0;
    ll size = 0;
    cin >> n >> m;
    ll x = n;
    vector<int> num;
    while (x != 0) {
        num.push_back(x % 10);
        x /= 10;
        i++;
    }
    for (int j = 0; j < m; ++j) {
        for (int k = 0; k < i; ++k) {
            num[k]++;
            if (num[k] >= 10) {
                num[k] = 0;
                num.insert(num.begin() + k + 1, 1);
                k++;
                i++;
            }
        }
    }
    size += num.size();
    size = size % (int)(pow((double)10, (double)9) + 7);
    cout << (size) << "\n";
}

int main() {
    IOS
    ll t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}