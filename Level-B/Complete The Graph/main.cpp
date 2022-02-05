#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll INF = LONG_LONG_MAX / 4;

struct Edge {
    int to;
    ll cost;
};

vector<vector<Edge>> adj_list;
vector<ll> dist;

vector<int> Dijkstra(int src, int n) {
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

        for (Edge edge : adj_list[index]){
            if (explored[edge.to]) continue;
            ll new_dist = dist[index] + edge.cost;

            if (new_dist < dist[edge.to]) {
                prev[edge.to] = index;
                dist[edge.to] = new_dist;
                pq.push({-1 * new_dist, edge.to});
            }
        }
    }
    return prev;
}

vector<int> find_shortest_path() {
    int n, m;
    cin >> n >> m;
    adj_list.resize(n + 1);
    dist.resize(n + 1, INF);
    dist[1] = 0;
    while (m--) {
        int from, to;
        ll weight;
        cin >> from >> to >> weight;

        adj_list[from].push_back((Edge){to, weight});
        adj_list[to].push_back((Edge){from, weight});
    }
    vector<int> prev, path;
    prev = Dijkstra(1, n);

    if (dist[n] == INF) {
        cout << -1;
        return {};
    }

    for (int at = n; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    return path;
}

int main() {
    IOS
    vector<int> path;
    path = find_shortest_path();
    reverse(path.begin(), path.end());

    for (int node : path) {
        cout << node << " ";
    }
    return 0;
}