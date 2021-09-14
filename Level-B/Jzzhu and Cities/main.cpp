#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll INF = LONG_LONG_MAX / 4;

vector<vector<pair<int, ll>>> adj_list;
vector<ll> dist, roads;
vector<pair<int, ll>> trains;

void Dijkstra(int src, int n) {
    vector<int> prev(n + 1, -1);
    vector<bool> explored(n + 1, false);
    priority_queue<pair<ll, int>> pq;
    pq.emplace(dist[src], src);

    while (!pq.empty()) {
        int index = pq.top().second;
        ll min_value = -1 * pq.top().first;
        pq.pop();

        if (dist[index] < min_value) continue;
        explored[index] = true;

        for (pair<ll, int> edge : adj_list[index]) {
            if (explored[edge.first]) continue;
            ll new_dist = dist[index] + edge.second;

            if (new_dist < dist[edge.first]) {
                roads[edge.first] = 1;
                prev[edge.first] = index;
                dist[edge.first] = new_dist;
                pq.push({-1 * new_dist, edge.first});
            } else if (new_dist == dist[edge.first]) roads[edge.first]++;
        }
    }
}

void find_shortest_path() {
    int n, m, k;
    cin >> n >> m >> k;
    adj_list.resize(n + 1);
    roads.resize(n + 1, 0);
    dist.resize(n + 1, LONG_LONG_MAX);
    dist[1] = 0;
    while (m--) {
        int from, to;
        ll weight;
        cin >> from >> to >> weight;

        adj_list[from].push_back({to, weight});
        adj_list[to].push_back({from, weight});
    }
    while (k--) {
        int from = 1, to;
        ll weight;
        cin >> to >> weight;

        trains.emplace_back(to, weight);
        adj_list[from].push_back({to, weight});
        adj_list[to].push_back({from, weight});
    }
    vector<int> prev, path;
    Dijkstra(1, n);

    int ans = 0;
    for (auto train : trains) {
        if (train.second > dist[train.first]) ans++;
        else if (dist[train.first] == train.second && roads[train.first] > 1) {
            ans++;
            roads[train.first]--;
        }
    }
    cout << ans;
}

int main() {
    IOS
    vector<int> path;
    find_shortest_path();
    return 0;
}