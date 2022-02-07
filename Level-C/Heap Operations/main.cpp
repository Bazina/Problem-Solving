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
    cin >> t;
    queue<string> operations;
    // can be multiset
    priority_queue<int , vector<int> , greater<>> heap;
    while (t--) {
        string op;
        cin >> op;
        int x;
        if (op != "removeMin") {
            cin >> x;
            if (op == "insert") {
                operations.push(op + " " + to_string(x));
                heap.push(x);
            } else if (op == "getMin") {
                while (!heap.empty() && heap.top() < x) {
                    operations.push("removeMin");
                    heap.pop();
                }

                if (heap.empty() || heap.top() > x) {
                    operations.push("insert " + to_string(x));
                    operations.push("getMin " + to_string(x));
                    heap.push(x);
                } else if (heap.top() == x) operations.push(op + " " + to_string(x));
            }
        } else {
            if (heap.empty()) {
                heap.push(0);
                operations.push("insert " + to_string(0));
            }
            heap.pop();
            operations.push(op);
        }
    }

    cout << operations.size() << "\n";
    while (!operations.empty()) {
        cout << operations.front() << "\n";
        operations.pop();
    }
    return 0;
}