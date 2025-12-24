#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int,int>>> &adj, int S) {
    const int INF = 1e9;

    vector<int> dist(V, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[S] = 0;
    pq.push({0, S});   // {dist, node}

    while (!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();

        // Lazy deletion check
        if (d != dist[node])
            continue;

        for (auto &[adjNode, edgeWeight] : adj[node]) {
            if (dist[adjNode] > d + edgeWeight) {
                dist[adjNode] = d + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main() {

    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // directed graph
        adj[u].push_back({v, w});
    }

    int S;   // source
    cin >> S;

    vector<int> dist = dijkstra(V, adj, S);

    cout << "Shortest distances from source " << S << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == 1e9) cout << "INF ";
        else cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
