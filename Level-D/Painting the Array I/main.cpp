#include <iostream>
#include <bits/stdc++.h>

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
#define cina(a, n)     for(int i = 0; i < n; i++){ cin >> a[i]; }
#define cinv(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i]; }
#define cinvP1(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].first; }
#define cinvP2(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].second; }
#define IOS ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define rep(i, a, b)    for(int i = a; i < b; i++)
#define isfind(a, s)  a.find(s) != a.npos

int main() {
    IOS
    int n, seg = 1;
    cin >> n;
    int a[n];
    cina(a, n)
    int el1 = a[0], el2 = -1;
    for (int i = 1; i < n; ++i) {
        if (i < n - 1 && a[i + 1] == el2){
            if (a[i] != el2){
                seg++;
                el2 = a[i];
            } else if (a[i] != el1) {
                seg++;
                el1 = a[i];
            }
            continue;
        }
        if (a[i] != el1) {
            seg++;
            el1 = a[i];
        } else if (a[i] != el2) {
            seg++;
            el2 = a[i];
        }
    }
    cout << seg;
    return 0;
}