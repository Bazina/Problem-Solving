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

vector<vector<string>> board{
        {"a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1"},
        {"a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2"},
        {"a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3"},
        {"a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4"},
        {"a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5"},
        {"a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6"},
        {"a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7"},
        {"a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8"}
};

int search(string src, string dst) {
    int ans = 1000000;
    vector<vector<bool>> vis(8, vector<bool>(8));
    queue<pair<string, int>> bfs;
    bfs.push(mp(src, 0));
    pair<string, int> curr = bfs.front();
    while (!bfs.empty()) {
        curr = bfs.front();
        vis[curr.first[1] - '1'][curr.first[0] - 'a'] = true;
        if (curr.first == dst) ans = min(curr.second, ans);
        bfs.pop();
        auto x = curr.first[1] - '1' + 1, y = curr.first[0] - 'a' + 2;
        if (curr.first[1] - '1' + 1 >= 0 && curr.first[1] - '1' + 1 < 8 && curr.first[0] - 'a' + 2 >= 0 && curr.first[0] - 'a' + 2 < 8 && !vis[curr.first[1] - '1' + 1][curr.first[0] - 'a' + 2]) bfs.push(mp(board[curr.first[1] - '1' + 1][curr.first[0] - 'a' + 2], curr.second + 1)), vis[curr.first[1] - '1' + 1][curr.first[0] - 'a' + 2] = true;
        if (curr.first[1] - '1' + 1 >= 0 && curr.first[1] - '1' + 1 < 8 && curr.first[0] - 'a' - 2 >= 0 && curr.first[0] - 'a' - 2 < 8 && !vis[curr.first[1] - '1' + 1][curr.first[0] - 'a' - 2]) bfs.push(mp(board[curr.first[1] - '1' + 1][curr.first[0] - 'a' - 2], curr.second + 1)), vis[curr.first[1] - '1' + 1][curr.first[0] - 'a' - 2] = true;
        if (curr.first[1] - '1' - 1 >= 0 && curr.first[1] - '1' - 1 < 8 && curr.first[0] - 'a' + 2 >= 0 && curr.first[0] - 'a' + 2 < 8 && !vis[curr.first[1] - '1' - 1][curr.first[0] - 'a' + 2]) bfs.push(mp(board[curr.first[1] - '1' - 1][curr.first[0] - 'a' + 2], curr.second + 1)), vis[curr.first[1] - '1' - 1][curr.first[0] - 'a' + 2] = true;
        if (curr.first[1] - '1' - 1 >= 0 && curr.first[1] - '1' - 1 < 8 && curr.first[0] - 'a' - 2 >= 0 && curr.first[0] - 'a' - 2 < 8 && !vis[curr.first[1] - '1' - 1][curr.first[0] - 'a' - 2]) bfs.push(mp(board[curr.first[1] - '1' - 1][curr.first[0] - 'a' - 2], curr.second + 1)), vis[curr.first[1] - '1' - 1][curr.first[0] - 'a' - 2] = true;
        if (curr.first[1] - '1' + 2 >= 0 && curr.first[1] - '1' + 2 < 8 && curr.first[0] - 'a' + 1 >= 0 && curr.first[0] - 'a' + 1 < 8 && !vis[curr.first[1] - '1' + 2][curr.first[0] - 'a' + 1]) bfs.push(mp(board[curr.first[1] - '1' + 2][curr.first[0] - 'a' + 1], curr.second + 1)), vis[curr.first[1] - '1' + 2][curr.first[0] - 'a' + 1] = true;
        if (curr.first[1] - '1' + 2 >= 0 && curr.first[1] - '1' + 2 < 8 && curr.first[0] - 'a' - 1 >= 0 && curr.first[0] - 'a' - 1 < 8 && !vis[curr.first[1] - '1' + 2][curr.first[0] - 'a' - 1]) bfs.push(mp(board[curr.first[1] - '1' + 2][curr.first[0] - 'a' - 1], curr.second + 1)), vis[curr.first[1] - '1' + 2][curr.first[0] - 'a' - 1] = true;
        if (curr.first[1] - '1' - 2 >= 0 && curr.first[1] - '1' - 2 < 8 && curr.first[0] - 'a' + 1 >= 0 && curr.first[0] - 'a' + 1 < 8 && !vis[curr.first[1] - '1' - 2][curr.first[0] - 'a' + 1]) bfs.push(mp(board[curr.first[1] - '1' - 2][curr.first[0] - 'a' + 1], curr.second + 1)), vis[curr.first[1] - '1' - 2][curr.first[0] - 'a' + 1] = true;
        if (curr.first[1] - '1' - 2 >= 0 && curr.first[1] - '1' - 2 < 8 && curr.first[0] - 'a' - 1 >= 0 && curr.first[0] - 'a' - 1 < 8 && !vis[curr.first[1] - '1' - 2][curr.first[0] - 'a' - 1]) bfs.push(mp(board[curr.first[1] - '1' - 2][curr.first[0] - 'a' - 1], curr.second + 1)), vis[curr.first[1] - '1' - 2][curr.first[0] - 'a' - 1] = true;
    }
    return ans;
}

void solve() {
    string src, dst;
    cin >> src >> dst;
    cout << search(src, dst) << endl;
}

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}