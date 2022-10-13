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
const int N = 1e3 + 10, mod = 1e9 + 7;
unordered_map<string, int> freq;

struct Node {
    Node *next[26]{};
    int maxFreq = 0;
    string best;

    Node() {
        memset(next, 0, sizeof next);
    }
} *root;

void insert(const string &st) {
    Node *cur = root;

    for (char i: st) {
        if (!cur->next[i - 'a'])
            cur->next[i - 'a'] = new Node();
        cur = cur->next[i - 'a'];

        if (cur->maxFreq < freq[st]) {
            cur->maxFreq = freq[st];
            cur->best = st;
        } else if (cur->maxFreq == freq[st] && st < cur->best)
            cur->best = st;
    }
}

void dfs(const string &st) {
    Node *cur = root;

    for (char i: st) {
        if (!cur->next[i - 'a']) {
            cout << "-1\n";
            return;
        }
        cur = cur->next[i - 'a'];
    }

    cout << cur->best << " " << cur->maxFreq << "\n";
}

void solve() {
    root = new Node();
    int n, q;

    cin >> n;
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        freq[s]++;
        insert(s);
    }

    cin >> q;
    string p;
    for (int i = 0; i < q; ++i) {
        cin >> p;
        dfs(p);
    }
}

int main() {
    IOS
    solve();
    return 0;
}