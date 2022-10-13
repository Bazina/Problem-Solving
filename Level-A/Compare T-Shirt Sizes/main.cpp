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
#define bsrch(a, n)    (binary_search((a).begin(), (a).end(), n))
#define srt(a)     (sort((a).begin() + 1, (a).end()))
#define revsrt(a)     (sort((a).rbegin(), (a).rend()))
#define rev(a)  (reverse((a).begin(), (a).end()))
#define sum(a)      (accumulate((a).begin(), (a).end(), 0ll))
#define cnt(a, i)  (count((a).begin(), (a).end(), i))
#define coutv(a)     for(int i = 0; i < (a).size(); i++) {cout << (a)[i] << " ";}
#define cinv(a)     for(int i = 0; i < (a).size(); i++){cin >> (a)[i];}
#define cinvP1(a)     for(int i = 0; i < (a).size(); i++){cin >> (a)[i].first;}
#define cinvP2(a)     for(int i = 0; i < (a).size(); i++){cin >> (a)[i].second;}
#define isfind(a, s)  a.find(s) != (a).npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b)    for(int (i) = a; (i) < (b); (i)++)
const int MAXN = 1e6;
const int mod = 1e9 + 7;
string s;

void solve() {
    int x1 = 0, x2 = 0;
    string s1, s2;

    cin >> s1 >> s2;

    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == 'X')
            x1++;
        if (s1[i] == 'M')
            x1 = 1;
    }
    if (s1[s1.size() - 1] == 'S')
        x1 *= -1;
    if (s1[s1.size() - 1] == 'L')
        x1 = (x1 == 0) ? 5 : x1 * 10;

    for (int i = 0; i < s2.size(); ++i) {
        if (s2[i] == 'X')
            x2++;
        if (s2[i] == 'M')
            x2 = 1;
    }
    if (s2[s2.size() - 1] == 'S')
        x2 *= -1;
    if (s2[s2.size() - 1] == 'L')
        x2 = (x2 == 0) ? 5 : x2 * 10;

    if (x1 == x2) {
        cout << "=\n";
        return;
    } else if (x1 > x2) {
        cout << ">\n";
        return;
    } else {
        cout << "<\n";
        return;
    }
}

int main() {
    //IOS
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}