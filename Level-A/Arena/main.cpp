#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

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
#define IOS ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define rep(i, a, b)    for(int i = a; i < b; i++)
#define isfind(a, s)  a.find(s) != a.npos

int main() {
    IOS
    int n, t, min, win, pos = 0, flag = 0;
    cin >> t;
    while (t--){
        cin >> n;
        vector<int> hero_lvl(n);
        cinv(hero_lvl)
        sort(hero_lvl.begin(), hero_lvl.end());
        min = hero_lvl[0];
        for (int i = 0; i < n; ++i) {
            if (min == hero_lvl[i]){
                flag = 1;
                continue;
            } else {
                flag = 0;
                pos = i;
                break;
            }
        }
        if (flag == 0){
            win = n - pos;
        } else {
            win = 0;
        }
        cout << win << "\n";
    }
    return 0;
}
