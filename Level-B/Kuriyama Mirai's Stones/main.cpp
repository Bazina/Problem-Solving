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
#define cinv(a)     for(int i = 1; i < a.size(); i++){cin >> a[i];}
#define cinvP1(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].first; }
#define cinvP2(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].second; }
#define isfind(a, s)  a.find(s) != a.npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    ll t;
    int n;
    cin >> n;
    vector<ll> cum1(n + 1), cum2(n + 1), elem1(n + 1), elem2(n + 1);
    cinv(elem1)
    cin >> t;
    elem2 = elem1;
    sort(elem2.begin(), elem2.end());
    for (int i = 1; i <= n; ++i) {
        cum1[i] = cum1[i - 1] + elem1[i];
        cum2[i] = cum2[i - 1] + elem2[i];
    }
    while (t--){
        int type, left, right;
        cin >> type >> left >> right;
        if (type == 1) {
            cout << cum1[right] - cum1[left - 1] << "\n";
        } else {
            cout << cum2[right] - cum2[left - 1] << "\n";
        }
    }
    return 0;
}