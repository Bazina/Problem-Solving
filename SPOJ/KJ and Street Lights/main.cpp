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
#define MOD 1000000007

void solve() {

}

int main() {
    IOS
    int n, p, dark = 0, ans = 0;
    cin >> n >> p;
    vector<int> lights(p + 1, 0), prefix(p + 1, 0);
    if (n == 0) {
        cout << p + 1;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        int x, y, start, end;
        cin >> x >> y;
        start = (x - y >= 0) ? x - y : 0;
        end = (x + y <= p) ? x + y : p;
        lights[start]++;
        if (end < p) lights[end + 1]--;
    }
    prefix[0] = lights[0];
    for (int i = 1; i <= p; ++i) {
        prefix[i] = prefix[i - 1] + lights[i];
    }
    for (int i = 0; i <= p; ++i) {
        if (prefix[i] > 1 || prefix[i] == 0) dark++;
        else  dark = 0;
        ans = max(dark, ans);
    }
    cout << ans;
    return 0;
}