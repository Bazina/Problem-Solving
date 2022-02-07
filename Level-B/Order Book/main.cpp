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
    int n, s, j = 0;
    cin >> n >> s;

    map<pair<char, int>, int> buyOrderBooks, sellOrderBooks;
    vector<pair<int, pair<char, int>>> buySortOrderBooks, sellSortOrderBooks, newSellSortOrderBooks;

    for (int i = 0; i < n; ++i) {
        int price, volume;
        char direction;

        cin >> direction >> price >> volume;

        if (direction == 'B') {
            buyOrderBooks[{direction, price}] += volume;
        } else {
            sellOrderBooks[{direction, price}] += volume;
        }
    }

    for (auto order: buyOrderBooks) {
        buySortOrderBooks.push_back({order.first.second, {order.first.first, order.second}});
    }

    for (auto order: sellOrderBooks) {
        sellSortOrderBooks.push_back({order.first.second, {order.first.first, order.second}});
    }

    revsrt(buySortOrderBooks);
    srt(sellSortOrderBooks);

    for (auto order : sellSortOrderBooks) {
        if (j == s) break;
        newSellSortOrderBooks.push_back(order);
        j++;
    }

    revsrt(newSellSortOrderBooks);
    for (auto order : newSellSortOrderBooks) {
        cout << order.second.first << " " << order.first << " " << order.second.second << "\n";
    }

    j = 0;
    for (auto order : buySortOrderBooks) {
        if (j == s) break;
        cout << order.second.first << " " << order.first << " " << order.second.second << "\n";
        j++;
    }
}

int main() {
    IOS
    solve();
    return 0;
}