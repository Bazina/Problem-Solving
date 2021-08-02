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


void solve(string s, int a, int b) {
    if (a == 0 && b == 0) {
        cout << s << endl;
        return;
    }
    if (a > 0) {
        string new_s = s + "(";
        solve(new_s, a - 1, b);
    }
    if (b > a) {
        string new_s = s + ")";
        solve(new_s, a, b - 1);
    }
}


int main() {
    int n;
    cin >> n;
    solve("", n, n);
    return 0;
}
 /*
int main() {
    IOS
    int n;
    cin >> n;
    queue<pair<string, int>> s;
    s.push(mp("", 0));
    while (true) {
        string p = s.front().first;
        int c = s.front().second;
        s.pop();
        if (p.size() == n * 2) {
            if (c == 0) {
                cout << p << endl;
            }
        } else if (p.size() > n * 2) {
            return 0;
        }
        s.push(mp(p + "(", c + 1));
        if (c > 0) {
            s.push(mp(p + ")", c - 1));
        }
    }
}
 */