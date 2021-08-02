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

// محاولة لعمل بحث ثنائي ولكنها فشلت
int binary_search_lower(vector<pair<pair<int, int>, bool>> tables, int size, int lo, int hi) {
    set<int> max;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (tables[mid].first.second == size && !(tables[mid].second)) {
            return mid;
        }
        if (tables[mid].first.second >= size && !(tables[mid].second)) {
            max.insert(mid);
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    if (max.empty()) {
        return -1;
    } else {
        return *max.begin();
    }
}

int main() {
    IOS
    int n, k, total_pay = 0, total_request = 0;
    cin >> n;
    vector<pair<pair<int, int>, int>> requests(n);
    vector<pair<int, int>> accepted;

    for (int i = 0; i < n; ++i) {
        int pay, size;
        cin >> size >> pay;
        requests[i].first.first = pay;
        requests[i].first.second = size;
        requests[i].second = i;
    }
    sort(requests.rbegin(), requests.rend());

    cin >> k;
    vector<pair<pair<int, int>, bool>> tables(k);

    for (int i = 0; i < k; ++i) {
        int table_size;
        cin >> table_size;
        tables[i].first.first = table_size;
        tables[i].first.second = i;
        tables[i].second = false;
    }
    sort(tables.begin(), tables.end());

    for (int i = 0; i < requests.size(); ++i) {
        int check_req_size = requests[i].first.second;
        for (int j = 0; j < k; ++j) {
            if (!(tables[j].second) && tables[j].first.first >= check_req_size) {
                tables[j].second = true;
                total_pay += requests[i].first.first;
                total_request++;
                int x1 = requests[i].second + 1;
                int x2 = tables[j].first.second + 1;
                accepted.emplace_back(x1, x2);
                break;
            }
        }
    }
    cout << total_request << " " << total_pay << endl;
    for (int i = 0; i < accepted.size(); ++i) {
        cout << accepted[i].first << " " << accepted[i].second << endl;
    }
    return 0;
}
