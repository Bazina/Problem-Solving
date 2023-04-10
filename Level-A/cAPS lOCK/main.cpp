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
    int u = 0, l = 0;
    bool first_char_is_lower = false;
    string s;
    cin >> s;

    if (islower(s[0])) {
        l++;
        first_char_is_lower = true;
    } else
        u++;

    for (int i = 1; i < s.size(); ++i) {
        if (islower(s[i]))
            l++;
        else
            u++;
    }

    if ((first_char_is_lower && u == s.size() - 1) || u == s.size()) {
        for (int i = 0; i < s.size(); ++i) {
            if (islower(s[i]))
                cout << (char) toupper(s[i]);
            else
                cout << (char) tolower(s[i]);
        }
    } else
        cout << s;
}

int main() {
    IOS
        solve();
    return 0;
}