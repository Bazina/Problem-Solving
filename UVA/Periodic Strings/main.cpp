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
#define srt(a)     (sort((a).begin(), (a).end()))
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
const int N = 1e6 + 10, mod = 1e9 + 7;
int fail[N], c = 0;

void kmp(string &s) {
    int n = (int) s.size();

    for (int i = 1; i < n; ++i) {
        int j = fail[i - 1];

        while (j > 0 and s[i] != s[j])
            j = fail[j - 1];

        if (s[i] == s[j])
            j++;

        fail[i] = j;
    }
}

void solve() {
    char s[1001];
    string s1;
    scanf("%s", s);

    s1 = s;
    kmp(s1);
    int last = fail[s1.size() - 1], n = (int) s1.size();

    if (n % (n - last) == 0)
        cout << n - last << '\n';
    else
        cout << n << '\n';
}

int main() {
    //IOS
    int t = 1;
    string q;
    scanf("%d", &t);
    while (t--) {
        solve();
        if (t)
            puts("");
    }
    return 0;
}