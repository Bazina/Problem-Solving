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
#define MOD 1000000007

void solve() {

}

int main() {
    vector<int> a(5);
    cinv(a)
    int n = a.size();
    int prfmn[n], prfmx[n];
    prfmn[n - 1] = a[n - 1];
    prfmx[0] = a[0];
    int mn = a[n - 1], mx = a[0];
    for (int i = n - 2; i >= 0; i--) {
        prfmn[i] = mn;
        mn = min(a[i], mn);
    }
    for (int i = 1; i < n; i++) {
        mx = max(a[i], mx);
        prfmx[i] = mx;
    }
    for (int i = 0; i < n; i++) {
        if (prfmx[i] <= prfmn[i]) {
            cout << i + 1;
            return 0;
        }
    }
    cout << n - 1;    // Writing output to STDOUT
    return 0;
}