#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main() {
    IOS
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int i = 0, j = i + k - 1, ans = 1e9;
    while (j < arr.size()) {
        ans = min(ans, arr[j] - arr[i]);
        i++, j = i + k - 1;
    }
    cout << ans;
    return 0;
}