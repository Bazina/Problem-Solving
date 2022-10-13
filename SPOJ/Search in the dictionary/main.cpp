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
vector<string> strs;

struct Node {
    Node *next[26]{};
    vector<int> indices;

    Node() {
        memset(next, 0, sizeof next);
    }
} *root;

void insert(string st, int id) {
    Node *cur = root;

    for (int i = 0; i < st.size(); ++i) {
        if (!cur->next[st[i] - 'a'])
            cur->next[st[i] - 'a'] = new Node();
        cur = cur->next[st[i] - 'a'];

        if (i != st.size() - 1)
            cur->indices.push_back(id);
    }
}

void dfs(const string &st) {
    Node *cur = root;

    for (char i : st) {
        if (!cur->next[i - 'a']) {
            cout << "No match.\n";
            return;
        }
        cur = cur->next[i - 'a'];
    }

    set<string> set;
    for (int index: cur->indices)
        set.insert(strs[index]);

    for (const string& str: set)
        cout << str << "\n";
}

void solve() {
    root = new Node();
    int n, k;

    cin >> n;
    strs.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
        insert(strs[i], i);
    }

    cin >> k;
    string p;
    for (int i = 1; i <= k; ++i) {
        cin >> p;
        cout << "Case #" << i << ":\n";
        dfs(p);
    }
}

int main() {
    IOS
    solve();
    return 0;
}