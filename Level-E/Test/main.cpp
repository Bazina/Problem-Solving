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
int fail[N];

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

vector<int> find_pattern(string &s, string &p) {
    vector<int> indices;
    int n = (int) s.size(), j = 0;

    kmp(p);

    for (int i = 0; i < n; ++i) {
        while (j > 0 and s[i] != p[j])
            j = fail[j - 1];

        if (s[i] == p[j])
            j++;

        if (j == p.size()) {
            indices.push_back(i - j + 1);
            j = fail[j - 1];
        }
    }

    return indices;
}

int go(string s1, string s2, string s3) {
    int cnt = (int) s1.size();
    vector<int> idx = find_pattern(s1, s2);
    if (idx.empty()) {
        string mix = s2 + " " + s1;
        kmp(mix);
        int intersection = fail[mix.size() - 1];

        cnt += (int) s2.size() - intersection;

        for (int i = intersection; i < s2.size(); ++i)
            s1 += s2[i];
    }

    idx = find_pattern(s1, s3);
    if (idx.empty()) {
        string mix = s3 + " " + s1;
        kmp(mix);
        int intersection = fail[mix.size() - 1];

        cnt += (int) s3.size() - intersection;
    }

    return cnt;
}

void solve() {
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];
    srt(s);

    int mn = INT_MAX;
    do {
        mn = min(mn, go(s[0], s[1], s[2]));
    } while (next_permutation(s.begin(), s.end()));

    cout << mn;
}

int main() {
    IOS
    solve();
    return 0;
}

/*
const int N = 1e6 + 10, mod = 1e9 + 7, b = 29, b2 = 31;
int pw[N], inv[N], pw2[N], inv2[N];

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

pair<int, int> get_hash_value(string &s) {
    int val1 = 0, val2 = 0;
    for (int i = 1; i <= s.size(); ++i) {
        int idx = s[i - 1] - 'a' + 1;
        val1 = add(val1, mul(idx, pw[i - 1]));
        val2 = add(val2, mul(idx, pw2[i - 1]));
    }
    return {val1, val2};
}

struct hashing {
    string s;
    int prefix[N]{}, prefix2[N]{};

    void generate_hash() {
        for (int i = 1; i <= s.size(); ++i) {
            int idx = s[i - 1] - 'a' + 1;
            prefix[i] = mul(idx, pw[i - 1]);
            prefix[i] = add(prefix[i], prefix[i - 1]);
            prefix2[i] = mul(idx, pw2[i - 1]);
            prefix2[i] = add(prefix2[i], prefix2[i - 1]);
        }
    }

    pair<int, int> get_hash(int l, int r) {
        int hash1 = mul(add(prefix[r], mod - prefix[l - 1]), inv[l - 1]);
        int hash2 = mul(add(prefix2[r], mod - prefix2[l - 1]), inv2[l - 1]);
        return {hash1, hash2};
    }
};

int go(hashing *h1, hashing *h2, hashing *h3) {
    int ans = 0, match = 0;
    string s;

    for (int i = 1; i <= h1->s.size(); ++i) {
        int len = min((int) h1->s.size() - i + 1, (int) h2->s.size());
        if (h1->get_hash(i, i + len - 1) == h2->get_hash(1, len)) {
            s += h2->s;
            match = 1;
            break;
        } else {
            s.push_back(h1->s[i - 1]);
        }
    }
    if (!match)
        s += h2->s;

    while (s.size() < h1->s.size())
        s.push_back((h1->s[s.size()]));

    auto h4 = new hashing();
    h4->s = s;
    h4->generate_hash();
    match = 0;

    for (int i = 1; i <= h4->s.size(); ++i) {
        int len = min((int) h4->s.size() - i + 1, (int) h3->s.size());
        if (h4->get_hash(i, i + len - 1) == h3->get_hash(1, len)) {
            ans += max((int) h3->s.size(), (int) h4->s.size() - i + 1);
            match = 1;
            break;
        } else
            ans++;
    }
    if (!match)
        ans += (int) h3->s.size();

    return ans;
}

void solve() {
    vector<int> v{0, 1, 2};
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    hashing *h[3] = {new hashing(), new hashing(), new hashing()};
    h[0]->s = s1, h[1]->s = s2, h[2]->s = s3;
    h[0]->generate_hash(), h[1]->generate_hash(), h[2]->generate_hash();

    int mn = INT_MAX;
    do {
        mn = min(mn, go(h[v[0]], h[v[1]], h[v[2]]));
    } while (next_permutation(v.begin(), v.end()));

    cout << mn;
}

 int main() {
    IOS
    pre();
    solve();
    return 0;
}
 */