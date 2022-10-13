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
bool f = false;

struct Node {
    Node *next[26]{};
    int cnt = 0;

    Node() {
        memset(next, 0, sizeof next);
    }
}*root;

void insert(const string& st) {
    Node *cur = root;

    for (char i : st) {
        if (!cur->next[i - '0'])
            cur->next[i - '0'] = new Node();
        cur = cur->next[i - '0'];
        cur->cnt++;
    }
    if (cur->cnt > 1)
        f = true;
}

void solve() {
    int n;
    f = false;
    cin >> n;
    vector<string> numbers(n);
    root = new Node();

    for (int i = 0; i < n; ++i)
        cin >> numbers[i];
    revsrt(numbers);

    for (int i = 0; i < n; ++i) {
        insert(numbers[i]);
        if (f) {
            cout << "NO\n";
            break;
        }
    }

    if (!f)
        cout << "YES\n";
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/*
const int N = 1e3 + 10, mod = 1e9 + 7, b = 29, b2 = 31;
int prefix[N], pw[N], inv[N], prefix2[N], pw2[N], inv2[N];

int mul(int x, int y) {
    return 1ll * x * y % mod;
}

int add(int x, int y) {
    return (x + y) % mod;
}

int fp(int base, int power) {
    if (power == 0)
        return 1;

    int temp = fp(base, power / 2);
    temp = mul(temp, temp);

    if (power & 1)
        temp = mul(temp, base);

    return temp;
}

void pre() {
    pw[0] = inv[0] = 1;
    pw2[0] = inv2[0] = 1;
    int mul_inv = fp(b, mod - 2);
    int mul_inv2 = fp(b2, mod - 2);
    for (int i = 1; i < N; ++i) {
        pw[i] = mul(b, pw[i - 1]);
        inv[i] = mul(inv[i - 1], mul_inv);
        pw2[i] = mul(b2, pw2[i - 1]);
        inv2[i] = mul(inv2[i - 1], mul_inv2);
    }
}

pair<int, int> get_hash(int l, int r) {
    int hash1 = mul(add(prefix[r], mod - prefix[l - 1]), inv[l - 1]);
    int hash2 = mul(add(prefix2[r], mod - prefix2[l - 1]), inv2[l - 1]);
    return {hash1, hash2};
}

pair<int, int> get_hash_value(string &s) {
    int val1 = 0, val2 = 0;
    for (int i = 1; i <= s.size(); ++i) {
        int idx = s[i - 1] - '0' + 1;
        val1 = add(val1, mul(idx, pw[i - 1]));
        val2 = add(val2, mul(idx, pw2[i - 1]));
    }
    return {val1, val2};
}

void generate_hash(string &s) {
    for (int i = 1; i <= s.size(); ++i) {
        int idx = s[i - 1] - '0' + 1;
        prefix[i] = mul(idx, pw[i - 1]);
        prefix[i] = add(prefix[i], prefix[i - 1]);
        prefix2[i] = mul(idx, pw2[i - 1]);
        prefix2[i] = add(prefix2[i], prefix2[i - 1]);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<string> numbers(n);
    vector<pair<int, int>> hashing(n);
    map<pair<int, int>, int> map;

    for (int i = 0; i < n; ++i)
        cin >> numbers[i];
    srt(numbers);

    for (int i = 0; i < n; ++i) {
        generate_hash(numbers[i]);

        for (int j = 1; j < numbers[i].size(); ++j)
            if (map[get_hash(1, j)]) {
                cout << "NO\n";
                return;
            }

        map[get_hash(1, (int) numbers[i].size())]++;
    }

    cout << "YES\n";
}

int main() {
    IOS
    pre();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
 */