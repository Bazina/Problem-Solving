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
    string s;
    cin >> s;
    int cnt = 1, maxi = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            cnt++;
            maxi = max(cnt, maxi);
            if (maxi >= 7)
                break;
        } else {
            cnt = 1;
        }
    }

    cout << ((maxi >= 7) ? "YES" : "NO");
}

int main() {
    IOS

    solve();
    return 0;
}