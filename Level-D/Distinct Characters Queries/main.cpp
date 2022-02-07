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


void solve() {

}

int main() {
    IOS
    string str;
    set<int> idx[26];
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        idx[str[i] - 'a'].insert(i);
    }

    int q;
    cin >> q;

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int pos;
            char c;
            cin >> pos >> c;

            idx[str[pos - 1] - 'a'].erase(idx[str[pos - 1] - 'a'].find(pos - 1));
            idx[c - 'a'].insert(pos - 1);
            str[pos - 1] = c;
        } else {
            int l, r;
            cin >> l >> r;
            l -= 1;
            r -= 1;

            int distinctChar = 0;
            for (auto &i: idx) {
                auto it = i.lower_bound(l);
                if (it != i.end() && *it <= r)
                    distinctChar++;
            }

            cout << distinctChar << "\n";
        }
    }
    return 0;
}