#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
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
#define srt(a)     (sort((a).begin() + 1, (a).end()))
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
int mod = 1e9 + 7;
pair<ll, ll> dp[17][33000];
int n;
ll hist[17];

pair<ll, ll> recur(int mask, ll last) {
    if (mask == (1 << n) - 1)
        return {hist[last], 1};

    pair<ll, ll> &ans = dp[last][mask];
    if (ans.first != -1)
        return ans;
    ans.first = ans.second = 0;

    for (int i = 0; i < n; ++i) {
        if ((mask >> i) & 1)
            continue;

        pair<ll, ll> temp = recur(mask | (1 << i), i);
        temp.first += abs(hist[i] - hist[last]);

        if (temp.first == ans.first)
            ans.second += temp.second;
        else
            ans = max(temp, ans);
    }

    return ans;
}

void solve() {
    while (cin >> n && n != 0) {
        for (int i = 0; i < n; ++i)
            cin >> hist[i];

        memset(dp, -1, sizeof dp);

        pair<ll, ll> ans = {0, 0};

        for (int i = 0; i < n; ++i) {
            pair<ll, ll> temp = recur(0 | (1 << i), i);
            temp.first += (n * 2 + hist[i]);

            if (temp.first == ans.first)
                ans.second += temp.second;
            else
                ans = max(temp, ans);
        }

        printf("%lld %lld\n", ans.first, ans.second);
    }
}

int main() {
    IOS
    solve();
    return 0;
}