#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll INF = 5 * 1e8;

vector<vector<ll>> dp, nxt;
vector<ll> q;

void propagate_negative_cycles(vector<vector<ll>> &dp_mat, unsigned long long size) {
    for (int k = 1; k < size; ++k) {
        for (int i = 1; i < size; ++i) {
            for (int j = 1; j < size; ++j) {
                if (dp[i][k] + dp[k][j] < dp[i][j]) {
                    dp[i][j] = -INF;
                    nxt[i][j] = -1;
                }
            }
        }
    }
}

void floyd_warshall(vector<vector<ll>> &mat, int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dp[i][k] + dp[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }

        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= k; ++j) {
                int x = n - k + 1;
                q[x] += dp[i][j];
            }
        }
    }
    //propagate_negative_cycles(dp, size);
}

void find_shortest_path() {
    int n;

    cin >> n;
    vector<ll> del(n + 1);
    vector<vector<ll>> adj_mat;
    adj_mat.resize(n + 1, vector<ll>(n + 1, INF));
    dp.resize(n + 1, vector<ll>(n + 1, INF));
    nxt.resize(n + 1, vector<ll>(n + 1, 0));
    q.resize(n + 1);

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            cin >> adj_mat[i][j];
            dp[i][j] = adj_mat[i][j];
            if (adj_mat[i][j] != INF) nxt[i][j] = j;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cin >> del[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x = del[n - i + 1], y = del[n - j + 1];
            dp[i][j] = adj_mat[x][y];
        }
    }

    floyd_warshall(adj_mat, n);

    for (int i = 1; i <= n; ++i) {
        cout << q[i] << " ";
    }
}

int main() {
    IOS
    find_shortest_path();

    return 0;
}