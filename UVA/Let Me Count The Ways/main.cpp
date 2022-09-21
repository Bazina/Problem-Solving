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
const int MAXN = 2e5 + 10;
vector<int> coins{50, 25, 10, 5, 1};
vector<vector<ll>> dp;
int n;

ll recur(int money, int i) {
    if (i >= 4)
        return 1;
    if (dp[i][money] != -1)
        return dp[i][money];

    ll ans = 0;
    if (coins[i] <= money)
        ans += recur(money - coins[i], i);
    ans += recur(money, i + 1);
    return dp[i][money] = ans;
}

int main() {
    //IOS
    dp.resize(6, vector<ll>(300000, -1));
    while (cin >> n) {
        if (n == 0) {
            cout << "There is only 1 way to produce 0 cents change." << "\n";
            continue;
        }

        ll ans = recur(n, 0);
        if (ans == 1)
            cout << "There is only 1 way to produce " << n << " cents change." << "\n";
        else
            cout << "There are " << ans << " ways to produce " << n << " cents change." << "\n";
    }
    return 0;
}