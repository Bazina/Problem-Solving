#include <bits/stdc++.h>
#include <iostream>
#include <string>

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
#define bsrch(a, n)    (binary_search(a.begin() , a.end() , n))
#define srt(a)     (sort(a.begin() , a.end()))
#define revsrt(a)     (sort(a.rbegin() , a.rend()))
#define rev(a)  (reverse(a.begin() , a.end()))
#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))
#define cnt(a, i)  (count(a.begin() , a.end() , i))
#define coutv(a)     for(int i=0; i<a.size() ; i++){cout<<a[i] << " ";}
#define cinv(a)     for(int i=0; i<a.size() ; i++){cin>>a[i];}
#define isfind(a, s)  a.find(s) != a.npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b)    for(int i = a; i < b; i++)

void solve() {
    string s;
    cin >> s;
    int size = s.size();
    int pos = -1;
    for (int i = 0; i < size && pos == -1; i++) {
        int newS = s.size() - 1 - i;
        if (s[i] != 'a') {
            pos = newS + 1;
        } else if (s[newS] != 'a') {
            pos = i;
        }
    }
    if (size % 2 == 1 && pos == -1) {
        int newS = size / 2;
        int i = size / 2;
        if (s[i] != 'a') {
            pos = newS + 1;
        } else if (s[newS] != 'a') {
            pos = i;
        }
    }

    if (pos == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    int m = 0;
    for (int i = 0; i < size + 1; i++) {
        if (pos == i) {
            cout << 'a';
            m++;
        } else {
            cout << s[i - m];
        }
    }
    cout << "\n";
}

int main() {
    IOS
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}