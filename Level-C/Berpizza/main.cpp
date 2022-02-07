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


void solve() {

}

struct myComp {
    constexpr bool operator()(
            pair<int, int> const& a,
            pair<int, int> const& b)
    const noexcept
    {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};

int main() {
    IOS
    int q, i = 0;
    cin >> q;
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> polyOrders;
    queue<pair<int, int>> monoOrders;
    vector<bool> orders(false);
    orders.push_back(false);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int p;
            cin >> p;
            i++;

            polyOrders.push({p, i});
            monoOrders.push({p, i});
            orders.push_back(false);
        } else if (t == 2) {
            while (orders[monoOrders.front().second]) {
                monoOrders.pop();
            }

            cout << monoOrders.front().second << " ";
            orders[monoOrders.front().second] = true;
            monoOrders.pop();
        } else {
            while (orders[polyOrders.top().second]) {
                polyOrders.pop();
            }

            orders[polyOrders.top().second] = true;
            cout << polyOrders.top().second << " ";
            polyOrders.pop();
        }
    };
    return 0;
}