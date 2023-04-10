#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define srt(a)     (sort((a).begin(), (a).end()))
#define revsrt(a)     (sort((a).rbegin(), (a).rend()))
#define rev(a)  (reverse((a).begin(), (a).end()))
#define coutv(a)     for(int i = 0; i < (a).size(); i++) {cout << (a)[i] << " ";}
#define cinv(a)     for(int i = 0; i < (a).size(); i++){cin >> (a)[i];}
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
ll MAXN = 1e6 + 5, mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int next = n, x;
    bool a[n + 1];
    memset(a, false, sizeof a);

    for (int i = 0; i < n; ++i) {
        cin >> x;
        a[x] = true;

        while (a[next]) {
            cout << next << ' ';
            next--;
        }
        cout << '\n';
    }
}

int main() {
    IOS
    solve();
    return 0;
}

/* Another Soln
void solve() {
    int n;
    cin >> n;
    int next = n;
    int a;
    priority_queue<int> q;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a == next) {
            next--;
            cout << a << ' ';
            while (!q.empty() && q.top() == next) {
                next--;
                cout << q.top() << ' ';
                q.pop();
            }
            cout << '\n';
        } else {
            q.push(a);
            cout << '\n';
        }
    }
}
 */