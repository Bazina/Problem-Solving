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


void solve() {
    int n, a = 0, b = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.length() - 1; ++i) {
        a = 0, b = 0;
        if (s[i] == 'b') b++;
        else a++;
        for (int j = i + 1; j < s.length(); ++j) {
            if (s[j] == 'b') b++;
            else a++;
            if (a == b && a != 0 && b != 0) {
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
    }
    cout << -1 << " " << -1 << endl;
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
