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

typedef struct assistant_time {
    ll t, y, z;
} assistant_time;

ll inflate(ll time, assistant_time assistant) {
    ll inflate_cnt = assistant.z * (time / (assistant.z * assistant.t + assistant.y));
    ll rem = time % (assistant.z * assistant.t + assistant.y);

    if (rem >= assistant.z * assistant.t)
        inflate_cnt += assistant.z;
    else
        inflate_cnt += rem / assistant.t;

    return inflate_cnt;
}

bool good(vector<assistant_time> &assistants, ll time, ll balloons) {
    ll n = 0;

    for (auto assistant: assistants)
        n += inflate(time, assistant);

    return n >= balloons;
}


void solve() {
    ll m, n;
    cin >> m >> n;

    vector<assistant_time> assistants(n);
    for (int i = 0; i < n; ++i)
        cin >> assistants[i].t >> assistants[i].z >> assistants[i].y;

    ll l = -1, r = 2e9 + 1;

    while (r > l + 1) {
        ll mid = (l + r) / 2;
        if (!good(assistants, mid, m))
            l = mid;
        else
            r = mid;
    }

    cout << r << "\n";
    for (auto assistant: assistants) {
        ll cnt = inflate(r, assistant);
        cout << min(m, cnt) << " ";
        m -= min(m, cnt);
    }

}

int main() {
    IOS
    solve();
    return 0;
}