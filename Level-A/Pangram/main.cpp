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
    int n;
    cin >> n;
    char c;
    bitset<26> b(0);
    for (int i = 0; i < n; ++i) {
        cin >> c;
        c = (char) tolower(c);
        if (!b[c - 'a'])
            b[c - 'a'].flip();
    }

    cout << ((b.all()) ? "YES\n" : "NO\n");
}

int main() {
    IOS
    solve();
    return 0;
}