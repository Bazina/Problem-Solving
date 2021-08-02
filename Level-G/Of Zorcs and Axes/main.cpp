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
    IOS
    int n, m, j = 0;
    cin >> n;
    vector<pair<pair<ll, ll>, int>> zorcs(n);
    set<pair<int, int>> filter;
    vector<int> accepted(n);

    for (int i = 0; i < n; ++i) {
        int curve, weight;
        cin >> weight >> curve;
        zorcs[i].first.first = weight;
        zorcs[i].first.second = curve;
        zorcs[i].second = i;
    }
    sort(zorcs.rbegin(), zorcs.rend());

    cin >> m;
    vector<pair<pair<ll, ll>, int>> axes(m);

    for (int i = 0; i < m; ++i) {
        int weight, curve;
        cin >> weight >> curve;
        axes[i].first.first = weight;
        axes[i].first.second = curve;
        axes[i].second = i;
    }
    sort(axes.rbegin(), axes.rend());

    for (int i = 0; i < zorcs.size(); ++i) {
        int check_weight = zorcs[i].first.first;
        int check_curve = zorcs[i].first.second;

        while (j < m && axes[j].first.first >= check_weight) {
            filter.insert(make_pair(axes[j].first.second, axes[j].second));
            j++;
        }
        auto curve = filter.lower_bound(make_pair(check_curve, 0));

        if (curve == filter.end()) {
            cout << -1 << endl;
            return 0;
        }
        accepted[zorcs[i].second] = curve->second;
        filter.erase(curve);
    }

    for (int i = 0; i < accepted.size(); ++i) {
        cout << accepted[i] + 1 << " ";
    }
    return 0;
}
