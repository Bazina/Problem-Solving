#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define srt(a)     (sort((a).begin(), (a).end()))
#define revsrt(a)     (sort((a).rbegin(), (a).rend()))
#define rev(a)  (reverse((a).begin(), (a).end()))
#define coutv(a)     for(int i = 0; i < (a).size(); i++) {cout << (a)[i] << " ";}
#define cinv(a)     for(int i = 0; i < (a).size(); i++){cin >> (a)[i];}
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll MAXN = 1e6 + 5, mod = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    string s;
    int freq[26] = {0};
    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < s.size(); ++j) {
            freq[s[j] - 'a']++;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (freq[i] % n != 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}