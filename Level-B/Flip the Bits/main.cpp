#include <bits/stdc++.h>
#include <iostream>
#include <string>

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
#define bsrch(a, n)    (binary_search(a.begin() , a.end() , n))
#define srt(a)     (sort(a.begin() , a.end()))
#define revsrt(a)     (sort(a.rbegin() , a.rend()))
#define rev(a)  (reverse(a.begin() , a.end()))
#define sum(a)      ( accumulate ((a).begin(), (a).end(), 0ll))
#define cnt(a, i)  (count(a.begin() , a.end() , i))
#define coutv(a)     for(int i=0; i<a.size() ; i++){cout<<a[i] << " ";}
#define cinv(a)     for(int i=0; i<a.size() ; i++){cin>>a[i];}
#define isfind(a, s)  a.find(s) != a.npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b)    for(int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (a == b) {
        cout << "YES\n";
    } else {
        int zero = 0;
        int one = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == '0') {
                zero++;
            } else {
                one++;
            }
        }
        bool unequal_equal = false;
        bool res = true;
        for (int i = n - 1; i >= 0 && res; i--) {
            if (a[i] != b[i] && !unequal_equal) {
                unequal_equal = true;
                if (zero != one) {
                    res = false;
                }
            } else if (a[i] == b[i] && unequal_equal) {
                unequal_equal = false;
                if (zero != one) {
                    res = false;
                }
            }

            if (a[i] == '0') {
                zero--;
            } else {
                one--;
            }
        }
        if (res && unequal_equal && (zero != one)) {
            res = false;
        }
        if (res) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    IOS
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}