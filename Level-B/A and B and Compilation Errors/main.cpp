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

int main() {
    IOS
    int n;
    cin >> n;
    map<int, int> first_errors, second_errors, third_errors;
    vector<int> errors(n);
    for (int i = 0; i < n; ++i) {
        int error;
        cin >> error;
        errors[i] = error;
        first_errors[error]++;
    }
    for (int i = 0; i < n - 1; ++i) {
        int error;
        cin >> error;
        second_errors[error]++;
    }
    for (int i = 0; i < n - 2; ++i) {
        int error;
        cin >> error;
        third_errors[error]++;
    }
    for (auto it : first_errors) {
        if (second_errors[it.first] == first_errors[it.first]){
            continue;
        } else {
            cout << it.first << endl;
            break;
        }
    }
    for (auto it : second_errors) {
        if (second_errors[it.first] == third_errors[it.first]){
            continue;
        } else {
            cout << it.first << endl;
            break;
        }
    }
    return 0;
}