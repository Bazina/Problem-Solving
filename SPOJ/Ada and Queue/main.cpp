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

}

int main() {
    IOS
    int t;
    bool rev = false;
    deque<ll> deque;
    cin >> t;
    while (t--) {
        string query;
        ll n;

        cin >> query;

        if (query[0] == 't') {
            cin >> n;
            if (rev) deque.push_back(n);
            else deque.push_front(n);
            continue;
        } else if (query[0] == 'p') {
            cin >> n;
            if (rev) deque.push_front(n);
            else deque.push_back(n);
            continue;
        }

        if (!deque.empty()) {
            if (query[0] == 'f') {
                if (rev) {
                    cout << deque.back() << "\n";
                    deque.pop_back();
                } else {
                    cout << deque.front() << "\n";
                    deque.pop_front();
                }
                continue;
            }
            else if (query[0] == 'b') {
                if (rev) {
                    cout << deque.front() << "\n";
                    deque.pop_front();
                } else {
                    cout << deque.back() << "\n";
                    deque.pop_back();
                }
                continue;
            }
            else if (query[0] == 'r') {
                rev = !rev;
                continue;
            }
        } else {
            if (query[0] != 'r' && query[0] != 't' && query[0] != 'p') cout << "No job for Ada?" << "\n";
        }
    }
    return 0;
}