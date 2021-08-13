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
#define cinvP1(a)     for(int i = 1; i < a.size(); i++){ cin >> a[i].first; }
#define cinvP2(a)     for(int i = 0; i < a.size(); i++){ cin >> a[i].second; }
#define isfind(a, s)  a.find(s) != a.npos
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i, a, b)    for(int i = a; i < b; i++)

vector<bool> vis;
vector<vector<int>> tree;
vector<int> seq, srt_seq;

bool solve(int src) {
    queue<int> bfs;
    bfs.push(src);
    vis[src] = true;
    int cnt = 2;
    while (!bfs.empty()) {
        int curr = bfs.front();
        bfs.pop();
        for (auto neighbour : tree[curr]) {
            if (!vis[neighbour]) {
                if (seq[cnt] != neighbour) return false;
                vis[neighbour] = true;
                bfs.push(neighbour);
                cnt++;
            }
        }
    }
    return cnt == tree.size();
}

bool cmp(int x, int y){
    return srt_seq[x] < srt_seq[y];
}

int main() {
    IOS
    tree.clear();
    vis.clear();
    seq.clear();
    srt_seq.clear();

    int n;
    cin >> n;
    tree.resize(n + 1);
    vis.resize(n + 1);
    seq.resize(n + 1);
    srt_seq.resize(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    for (int i = 1; i < seq.size(); ++i) {
        cin >> seq[i];
        srt_seq[seq[i]] = i;
    }

    for (int i = 1; i < tree.size(); ++i) {
        sort(tree[i].begin(), tree[i].end(), cmp);
    }

    if (seq[1] != 1) {
        cout << "No";
        return 0;
    }

    if (solve(1)) cout << "Yes";
    else cout << "No";

    return 0;
}
