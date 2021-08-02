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

void solve() {
    return;
}

int main() {
    IOS
    int n;
    cin >> n;
    vector<pair<int, int>> lab(n);
    for (int i = 0; i < n; ++i) {
        int price, qua;
        cin >> price >> qua;
        lab[i].first = price;
        lab[i].second = qua;
    }
    bool flag = false;
    sort(lab.begin(), lab.end());
    for (int i = 1; i < n; ++i) {
        if (lab[i - 1].first < lab[i].first && lab[i - 1].second > lab[i].second) {
            flag = true;
            break;
        }

    }
    if (flag) cout << "Happy Alex" << endl;
    else cout << "Poor Alex" << endl;
    return 0;
}
