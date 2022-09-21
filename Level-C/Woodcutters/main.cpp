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
const int MAXN = 1e5 + 5;
ll coordinate[MAXN], height[MAXN];
ll dp[MAXN][2];
int n;

ll recur(int i, int cutOnRight) {
    if (i > n)
        return 0;
    if (dp[i][cutOnRight] != -1)
        return dp[i][cutOnRight];

    ll ans1 = 0, ans2 = 0, ans3, ans;
    if (height[i] + coordinate[i] < coordinate[i + 1])
        ans1 = recur(i + 1, 1) + 1;

    if ((cutOnRight && coordinate[i] - height[i] > height[i - 1] + coordinate[i - 1]) ||
        (!cutOnRight && coordinate[i] - height[i] > coordinate[i - 1]))
        ans2 = recur(i + 1, 0) + 1;

    ans3 = recur(i + 1, 0);

    dp[i][cutOnRight] = ans = max(ans1, max(ans2, ans3));
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> coordinate[i] >> height[i];

    memset(dp, -1, sizeof dp);
    coordinate[n + 1] = INT_MAX, height[n + 1] = 0;
    coordinate[0] = INT_MIN, height[0] = 0;

    cout << recur(1, 0) << "\n";
}

int main() {
    IOS
    solve();
    return 0;
}