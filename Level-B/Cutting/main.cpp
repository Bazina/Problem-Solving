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
    int n, b, net = 0, ans = 0;
    int even = 0, odd = 0;
    cin >> n >> b;
    vector<int> cut(n);
    vector<int> bitcoin;
    cinv(cut)
    for (int i = 0; i < n; ++i) {
        if (cut[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
        if (odd == even && i < cut.size() - 1) {
            bitcoin.push_back(abs(cut[i + 1] - cut[i]));
        }
    }
    sort(bitcoin.begin(), bitcoin.end());
    for (int i = 0; i < bitcoin.size(); ++i) {
        if (net <= b) {
            net += bitcoin[i];
            ans++;
        } else {
            net -= bitcoin[i - 1];
            ans--;
            break;
        }
    }
    if (net > b){
        net -= bitcoin.back();
        ans--;
    }
    cout << ans;
}

int main() {
    IOS
    solve();
    return 0;
}