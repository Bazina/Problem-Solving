#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll INF = 2000000000;

vector<vector<pair<int, ll>>> adj_list;
vector<ll> dist;
vector<set<ll>> times;

void Dijkstra(int src, int n) {
    vector<int> prev(n + 1, -1);
    vector<bool> explored(n + 1, false);
    priority_queue<pair<ll, int>> pq;
    pq.emplace(dist[src], src);

    while (!pq.empty()) {
        int index = pq.top().second;
        ll min_value_weight = -1 * pq.top().first;
        pq.pop();

        if (dist[index] < min_value_weight) continue;
        explored[index] = true;

        while (times[index].find(min_value_weight) != times[index].end()) min_value_weight++;

        for (pair<ll, int> edge : adj_list[index]) {
            if (explored[edge.first]) continue;
            ll new_dist = min_value_weight + edge.second;

            if (new_dist < dist[edge.first]) {
                prev[edge.first] = index;
                dist[edge.first] = new_dist;
                pq.push({-1 * new_dist, edge.first});
            }
        }
    }
}

void find_shortest_path() {
    int n, m, k;
    cin >> n >> m;
    adj_list.resize(n + 1);
    dist.resize(n + 1, LONG_LONG_MAX);
    times.resize(n + 1);
    dist[1] = 0;
    while (m--) {
        int from, to;
        ll weight;
        cin >> from >> to >> weight;

        adj_list[from].push_back({to, weight});
        adj_list[to].push_back({from, weight});
    }
    for (int i = 1; i < n + 1; ++i) {
        cin >> k;
        for (int j = 0; j < k; ++j) {
            ll ti;
            cin >> ti;
            times[i].insert(ti);
        }
    }
    vector<int> prev, path;
    Dijkstra(1, n);

    if (dist[n] >= INF) {
        cout << -1;
    } else {
        cout << dist[n];
    }
}

int main() {
    IOS
    vector<int> path;
    find_shortest_path();
    return 0;
}