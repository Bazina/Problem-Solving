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
#define cinv(a)     for(int i = 1; i < a.size(); i++){cin >> a[i];}
#define cinvP1(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].first; }
#define cinvP2(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].second; }
#define isfind(a, s)  a.find(s) != a.npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b)    for(int i = a; i < b; i++)

int main() {
    IOS
    ll t;
    string str;
    cin >> str >> t;
    vector<int> cum(str.length() + 1), elem(str.length() + 1);
    cum[0] = 0;
    for (int i = 0, j = 1; i < str.length(); ++i, ++j) {
        if (str[i] == '.' && str [i + 1] == '.' ||
            str[i] == '#' && str [i + 1] == '#') {
            elem[j] = 1;
        } else if (i == str.length() - 1 && (str[i] == '.' && str [i - 1] == '.' ||
                   str[i] == '#' && str [i - 1] == '#')) {
            elem[j] = 1;
        } else {
            elem[j] = 0;
        }
    }
    for (int j = 1; j < str.length() + 1; ++j) {
        cum[j] = elem[j] + cum[j - 1];
    }
    while (t--){
        int left, right, seq;
        cin >> left >> right;
        seq = cum[right - 1] - cum[left - 1];

        cout << seq << "\n";
    }
    return 0;
}