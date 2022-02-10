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
#define bsrch(a, n)    (binary_search((a).begin(), (a).end(), n))
#define srt(a)     (sort((a).begin(), (a).end()))
#define revsrt(a)     (sort((a).rbegin(), (a).rend()))
#define rev(a)  (reverse((a).begin(), (a).end()))
#define sum(a)      (accumulate((a).begin(), (a).end(), 0ll))
#define cnt(a, i)  (count((a).begin(), (a).end(), i))
#define coutv(a)     for(int i = 0; i < (a).size(); i++) {cout << (a)[i] << " ";}
#define cinv(a)     for(int i = 0; i < (a).size(); i++){cin >> (a)[i];}
#define cinvP1(a)     for(int i = 0; i < (a).size(); i++){cin >> (a)[i].first;}
#define cinvP2(a)     for(int i = 0; i < (a).size(); i++){cin >> (a)[i].second;}
#define isfind(a, s)  a.find(s) != (a).npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b)    for(int (i) = a; (i) < (b); (i)++)


void subsetsUtil(vector<string> &A, vector<vector<string> > &res,
                 vector<string> &subset, int index) {
    res.push_back(subset);
    for (int i = index; i < A.size(); i++) {

        // include the A[i] in subset.
        subset.push_back(A[i]);

        // move onto the next element.
        subsetsUtil(A, res, subset, i + 1);

        // exclude the A[i] from subset and triggers
        // backtracking.
        subset.pop_back();
    }
}

// below function returns the subsets of vector A.
vector<vector<string>> subsets(vector<string> &A) {
    vector<string> subset;
    vector<vector<string> > res;

    // keeps track of current element in vector A;
    int index = 0;
    subsetsUtil(A, res, subset, index);

    return res;
}

void solve() {
    int n, m, maxi = 0, idxK = 0;
    bool conflict = false;
    cin >> n >> m;
    vector<string> names(n);
    set<pair<string, string>> bad;
    cinv(names)
    for (int i = 0; i < m; ++i) {
        string x, y;
        cin >> x >> y;
        bad.insert({x, y});
    }

    auto ans = subsets(names);
    for (int k = 0; k < ans.size(); ++k) {
        conflict = false;
        if (ans[k].size() <= 1) {
            if (maxi < ans[k].size()) {
                idxK = k;
                maxi = ans[k].size();
            }
            continue;
        }
        for (int i = 0; i < ans[k].size() - 1; ++i) {
            for (int j = i + 1; j < ans[k].size(); ++j) {
                if (bad.count(make_pair(ans[k][i], ans[k][j])) || bad.count(make_pair(ans[k][j], ans[k][i]))) {
                    conflict = true;
                    break;
                }
            }
            if (conflict) break;
        }
        if (!conflict) {
            if (maxi < ans[k].size()) {
                idxK = k;
                maxi = ans[k].size();
            }
        }
    }

    cout << ans[idxK].size() << "\n";
    srt(ans[idxK]);
    for (auto &name: ans[idxK]) {
        cout << name << "\n";
    }
}

int main() {
    IOS
    solve();
    return 0;
}