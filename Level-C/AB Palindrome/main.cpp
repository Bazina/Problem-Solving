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
#define isfind(a,s)  a.find(s) != a.npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i , a, b)    for(int i = a; i < b; i++)

void solve() {
    int a, b, flag = 1;
    cin >> a >> b;
    string s1;
    cin >> s1;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == '1') {
            b--;
        } else if (s1[i] == '0') {
            a--;
        }
    }
    for (int i = 0, j = s1.size() - 1; i < s1.size() / 2; ++i, --j) {
        if (s1[i] == '?' && s1[j] != '?' && (a != 0 || b != 0)){
            if (s1[j] == '1' && b != 0) {
                s1[i] = '1';
                b--;
            } else if (s1[j] == '0' && a != 0) {
                s1[i] = '0';
                a--;
            }
        } else if (s1[i] != '?' && s1[j] == '?' && (a != 0 || b != 0)) {
            if (s1[i] == '1' && b != 0) {
                s1[j] = '1';
                b--;
            } else if (s1[i] == '0' && a != 0) {
                s1[j] = '0';
                a--;
            }
        } else if (s1[i] == '?' && s1[j] == '?') {
            if (b != 0 && b >= 2 && b > a) {
                s1[i] = '1';
                s1[j] = '1';
                b -= 2;
            } else if (a != 0 && a >= 2 && b <= a) {
                s1[i] = '0';
                s1[j] = '0';
                a -= 2;
            } else if (a != 0 && a >= 2) {
                s1[i] = '0';
                s1[j] = '0';
                a -= 2;
            } else if (b != 0 && b >= 2) {
                s1[i] = '1';
                s1[j] = '1';
                b -= 2;
            } else {
                a = 0;
                b = 0;
            }
        } else if (a == 0 && b == 0 && (s1[i] == '?' || s1[j] == '?')){
            cout << -1 << '\n';
            return;
        }
    }
    if (s1.size() % 2 == 1 && s1[(s1.size() / 2)] == '?') {
        if (a != 0) {
            s1[(s1.size() / 2)] = '0';
            a--;
        } else if (b != 0) {
            s1[(s1.size() / 2)] = '1';
            b--;
        }
    }
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == '?') {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 0, j = s1.size() - 1; i < s1.size() / 2; ++i, --j) {
        if (s1[i] == s1[j]) {
            flag = 1;
            continue;
        } else {
            flag = 0;
            break;
        }
    }
    if (flag && a == 0 && b == 0) {
        cout << s1 << "\n";
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    IOS
    ll t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}