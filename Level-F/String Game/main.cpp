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

bool good(int index, vector<int> &idx, string &t, string &p) {
    int cnt = 0;
    vector<bool> flags(t.size());
    for (int i = 0; i < index; ++i)
        flags[idx[i] - 1] = true;

    for (int i = 0; i < t.size() && cnt < p.size(); ++i)
        if (!flags[i] && t[i] == p[cnt])
            cnt++;

    return cnt == p.size();
}


void solve() {
    string t, p;
    cin >> t >> p;

    vector<int> idx(t.size());
    cinv(idx)

    int l = 0;
    int r = (int) t.size();

    while (r > l + 1) {
        int m = (l + r) / 2;
        if (good(m, idx, t, p))
            l = m;
        else
            r = m;
    }

    cout << l;
}

int main() {
    IOS
    solve();
    return 0;
}