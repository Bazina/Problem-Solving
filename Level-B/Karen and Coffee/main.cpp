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

typedef struct recipe {
    int l, r;
} recipe;

int n, k, q;
vector<recipe> recipes;

void solve() {
    int maxi = 0, mini = 2000000;
    cin >> n >> k >> q;

    vector<int> temp(200002, 0), copy(200002, 0);
    recipes.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> recipes[i].l >> recipes[i].r;
        temp[recipes[i].l]++;
        temp[recipes[i].r + 1]--;

        if (maxi < recipes[i].l)
            maxi = recipes[i].l;
        if (maxi < recipes[i].r)
            maxi = recipes[i].r;
        if (mini > recipes[i].l)
            mini = recipes[i].l;
        if (mini > recipes[i].r)
            mini = recipes[i].r;
    }

    for (int i = mini; i <= maxi; ++i)
        temp[i] = temp[i - 1] + temp[i];

    for (int i = 1; i <  200002; ++i) {
        if (temp[i] >= k) temp[i] = 1;
        else temp[i] = 0;
        temp[i] = temp[i - 1] + temp[i];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        cout << temp[b] - temp[a - 1] << "\n";
    }
}

int main() {
    IOS
    solve();
    return 0;
}