#include <iostream>
#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define maxv(a)    (*max_element((a).begin(), (a).end()))
#define bsrch(a , n)    (binary_search(a.begin() , a.end() , n))
#define srt(a)    (sort(a.begin() , a.end()))
#define rev(a)    (reverse(a.begin() , a.end()))
#define sum(a)    (accumulate ((a).begin(), (a).end(), 0ll))
#define cnt(a,i)    (count(a.begin() , a.end() , i))
#define coutv(a)    for(int i = 0; i < a.size() ; i++){ cout << a[i] << " "; }
#define cinv(a)    for(int i = 0; i < a.size() ; i++){ cin >> a[i]; }
#define IOS    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define rep(i , a, b)    for(int i = a; i < b; i++)

using namespace std;

int main() {
    int t, n, pos, i, noprint = 1;
    long k;
    cin >> t;
    while (t--){
        noprint = 1;
        cin >> n >> k;
        vector<int> mounts(n);
        cinv(mounts);
        for (i = 1; k != 0; ++i) {
            if (mounts[0] >= mounts[1] && i < n - 1){
                if (mounts[i] < mounts[i + 1]){
                    noprint = 1;
                    mounts[i] += 1;
                    k--;
                    pos = i + 1;
                    i = 0;
                    continue;
                } else if (mounts[i] >= mounts[i + 1]){
                    continue;
                }
            } else if (mounts[0] < mounts[1] && i < n - 1){
                mounts[0] += 1;
                i = 0;
                k--;
                pos = 1;
            } else if (i >= n - 1){
                if (n == 2 && i == 1 && k + mounts[0] <= mounts[1]){
                    noprint = 0;
                    cout << "1" << "\n";
                    break;
                } else {
                    noprint = 0;
                    cout << "-1" << "\n";
                    break;
                }
            }
        }
        if (noprint) {
            cout << pos << "\n";
        }
    }
    return 0;
}
