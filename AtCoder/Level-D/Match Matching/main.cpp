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
#define bsrch(a, n)    (binary_search(a.begin(), a.end() , n))
#define srt(a)     (sort(a.begin(), a.end()))
#define revsrt(a)     (sort(a.rbegin(), a.rend()))
#define rev(a)  (reverse(a.begin(), a.end()))
#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))
#define cnt(a, i)  (count(a.begin(), a.end(), i))
#define coutv(a)     for(int i=0; i<a.size(); i++){cout<<a[i] << " ";}
#define cinv(a)     for(int i = 0; i < a.size(); i++){cin >> a[i];}
#define cinvP1(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].first; }
#define cinvP2(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].second; }
#define isfind(a, s)  a.find(s) != a.npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b)    for(int i = a; i < b; i++)


int main() {
    const int maxi = 1e4 + 7;
    vector<int> dp(maxi, 1);
    vector<int> weight {0, 2, 5, 5, 4, 5, 6, 3, 7, 6}, A(10);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= m; i++)
        for (int j = weight[A[i]]; j <= n; j++)
            dp[j] = max(dp[j], dp[j - weight[A[i]]] + 1);
    sort(A.begin(), A.end() + m);
    while (n) {
        if (dp[n] == dp[n - weight[A[m]]] + 1) {
            cout << A[m];
            n -= weight[A[m]];
        } else {
            --m;
        }
    }
    return 0;
}
