#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define maxv(a)      (*max_element((a).begin(), (a).end()))
#define bsrch(a, n)    (binary_search(a.begin(), a.end(), n))
#define srt(a)     (sort(a.begin(), a.end()))
#define rev(a)  (reverse(a.begin(), a.end()))
#define sum(a)      (accumulate ((a).begin(), (a).end(), 0ll))
#define cnt(a,i)  (count(a.begin(), a.end(), i))
#define coutv(a)     for(int i = 0; i < a.size(); i++){ cout << a[i] << " "; }
#define cinv(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i]; }
#define cinvP1(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].first; }
#define cinvP2(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].second; }
#define IOS ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define rep(i, a, b)    for(int i = a; i < b; i++)
#define isfind(a, s)  a.find(s) != a.npos

int main() {
    IOS
    int t, n;
    long A, B;
    cin >> t;
    while (t--) {
        cin >> A >> B >> n;
        vector<pair<long, long>> monsters(n);
        cinvP1(monsters);
        cinvP2(monsters);
        sort(monsters.begin(), monsters.end());
        for (int i = 0; i < monsters.size(); ++i) {
            B -= monsters[i].first;
            monsters[i].second -= A;
            if (B <= 0) {
                if (i == monsters.size() - 1 && monsters[i].second <= 0) {
                    cout << "YES" << "\n";
                    break;
                } else {
                    cout << "NO" << "\n";
                    break;
                }
            } else if (B > 0 && monsters[i].second <= 0) {
                if (i == monsters.size() - 1) {
                    cout << "YES" << "\n";
                    break;
                } else {
                    continue;
                }
            } else if (monsters[i].second > 0 && B > 0) {
                i--;
                continue;
            }
        }
    }
    return 0;
}
