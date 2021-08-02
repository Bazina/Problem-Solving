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
#define all(v)			((v).begin()), ((v).end())
#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define bsrch(a , n)    (binary_search(a.begin() , a.end() , n))
#define srt(a)     (sort(a.begin() , a.end()))
#define revsrt(a)     (sort(a.rbegin() , a.rend()))
#define rev(a)  (reverse(a.begin() , a.end()))
#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))
#define cnt(a,i)  (count(a.begin() , a.end() , i))
#define coutv(a)     for(int i=0; i<a.size() ; i++){cout<<a[i] << " ";}
#define cinv(a)     for(int i=0; i<a.size() ; i++){cin>>a[i];}
#define cinvP1(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].first; }
#define cinvP2(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].second; }
#define isfind(a,s)  a.find(s) != a.npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)

void solve() {
    int n, m, ans1 = 0, ans2 = 0;
    cin >> n >> m;
    priority_queue<int> min_people, max_people;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        min_people.push(-1 * x);
        max_people.push(x);
    }
    for (int i = 0; i < n; ++i) {
        int z = max_people.top();
        ans1 += z;
        max_people.pop();
        if (z != 1) {
            max_people.push(z - 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        int z = min_people.top();
        ans2 += -1 * z;
        min_people.pop();
        if (z != -1) {
            min_people.push(z + 1);
        }
    }
    cout << ans1 << " " << ans2;
}

int main() {
    IOS
    solve();
    return 0;
}