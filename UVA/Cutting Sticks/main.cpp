#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int cuts[55], dp[1100][1100];

int recur(int i, int j) {
    if (i + 1 == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i + 1; k < j; ++k)
        ans = min(ans, cuts[j] - cuts[i] + recur(i, k) + recur(k, j));

    dp[i][j] = ans;
    return ans;
}

int main() {
    IOS
    int l, n;
    while (cin >> l && l) {
        cin >> n;
        cuts[0] = 0;
        cuts[n + 1] = l;
        for (int i = 1; i <= n; ++i)
            cin >> cuts[i];

        memset(dp, -1, sizeof dp);
        cout << "The minimum cutting is " << recur(0, n + 1) << ".\n";
    }
    return 0;
}