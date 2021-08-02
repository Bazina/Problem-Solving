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
vector<int> power;
vector<set<int>> friends;
vector<bool> alive;
vector<int> Cpower;
vector<set<int>> Cfriends;
vector<bool> Calive;

void solve() {
    for (int i = 1; i < friends.size(); ++i) {
        if (friends[i].size() == abs(power[i]) && power[i] < 0 && alive[i]) {
            alive[i] = false;
            for (int j = 1; j < friends.size(); ++j) {
                if (i == j || !alive[j]) continue;
                auto x = friends[j].find(i);
                if (x != friends[j].end() && i > j && i != j) power[j]++;
                else if (x != friends[j].end() && i < j && i != j) power[j]--;
                friends[j].erase(i);
            }
        }
    }
}

int main() {
    IOS
    int n, m, q;
    cin >> n >> m;
    power.resize(n + 1);
    alive.resize(n, true);
    friends.resize(n + 1);
    Cpower.resize(n + 1);
    Calive.resize(n, true);
    Cfriends.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        friends[x].insert(y), Cfriends[x].insert(y);
        friends[y].insert(x), Cfriends[y].insert(x);
        if (x > y) power[x]++, power[y]--, Cpower[x]++, Cpower[y]--;
        else if (y > x) power[x]--, power[y]++, Cpower[x]--, Cpower[y]++;
    }
    int last_c;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        if (last_c == 3) {
            friends = Cfriends;
            alive = Calive;
            power = Cpower;
        }
        int v, u, c, count = 0;
        cin >> c;
        last_c = c;
        if (c == 3) {
            solve();
            for (int j = 0; j < alive.size(); ++j) {
                if (alive[j]) count++;
            }
            cout << count << endl;
        }
        if (c == 1) {
            cin >> u >> v;
            friends[u].insert(v);
            friends[v].insert(u);
            if (v > u) power[v]++, power[u]--;
            else if (u > v) power[v]--, power[u]++;
        } else if (c == 2) {
            cin >> u >> v;
            friends[u].erase(v);
            friends[v].erase(u);
            if (v > u) power[v]--, power[u]++;
            else if (u > v) power[v]++, power[u]--;
        }
    }
    return 0;
}