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
int q, t, k, l, x;
string s, strs[N];
map<pair<int, int>, int> freq;

struct Node {
    Node *next[26]{};
    int cnt = 0;

    Node() {
        memset(next, 0, sizeof next);
    }
} *root;

void insert(const string &st) {
    Node *cur = root;
    int len = 0;

    for (int i = (int) st.size() - 1; i >= 0; --i) {
        int ch = st[i] - 'a';
        if (!cur->next[ch])
            cur->next[ch] = new Node();
        cur = cur->next[ch];
        cur->cnt++;
        len++;
        freq[{cur->cnt, len}]++;
    }
}

void remove(const string &st) {
    Node *cur = root;
    int len = 0;

    for (int i = (int) st.size() - 1; i >= 0; --i) {
        int ch = st[i] - 'a';
        if (!cur->next[ch])
            cur->next[ch] = new Node();
        cur = cur->next[ch];
        len++;
        freq[{cur->cnt, len}]--;
        cur->cnt--;
    }
}

void solve() {
    root = new Node();

    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> q;
        if (q == 1) {
            cin >> s;
            insert(s);
            strs[i] = s;
        } else if (q == 2) {
            cin >> k >> l;
            cout << ((freq[{k, l}] > 0) ? "YES\n" : "NO\n");
        } else {
            cin >> x;
            if (!strs[x].empty()) {
                remove(strs[x]);
                strs[x] = "";
            }
        }
    }
}

int main() {
    IOS
    solve();
    return 0;
}