#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

void print(int pos, int k, vector<ll> &book, ull mid) {
    ull count = 0;
    int pos_till = -1;
    for (int i = pos; i >= 0; i--) {
        if (count + book[i] > mid || i == k - 2) {
            print(i, k - 1, book, mid);
            pos_till = i;
            break;
        }
        count += book[i];
    }
    if (pos_till >= 0)
        printf("/ ");
    for (int i = pos_till + 1; i <= pos; i++)
        printf("%d ", book[i]);
}

bool check(int k, vector<ll> &book, ull mid) {
    int n = book.size(), i = 0, scribes = 1;
    ull count = 0;
    while (i < n) {
        if (book[i] > mid) return false;
        if (book[i] + count > mid) scribes++, count = 0;
        if (count <= mid) count += book[i], i++;
    }
    if (scribes <= k) return true;
    return false;
}

ull BS(vector<ll> &book, int k) {
    ull lo = 1, hi = LLONG_MAX, mid, ans = LLONG_MAX;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (check(k, book, mid)) {
            ans = min(ans, mid);
            hi = mid;
        } else
            lo = mid + 1;
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> book;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        book.push_back(x);
    }
    book.push_back(0);
    ull ans = BS(book, k);
    print(book.size() - 2, k, book, ans);
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}