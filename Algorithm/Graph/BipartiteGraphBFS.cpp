#include <bits/stdc++.h>
using namespace std;

// Bipartite check using BFS
bool isBipartite(int n, vector<vector<int>>& adj) {
    vector<int> color(n, -1); // -1 = uncolored, 0 & 1 = two colors
    queue<int> q;

    // Handle disconnected graph
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neigh : adj[node]) {
                    if (color[neigh] == -1) {
                        color[neigh] = !color[node];
                        q.push(neigh);
                    }
                    else if (color[neigh] == color[node]) {
                        return false; // odd cycle found
                    }
                }
            }
        }
    }
    return true;
}


int main() {
    int n, m;
    cin >> n >> m;  // n = number of nodes, m = number of edges

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    if (isBipartite(n, adj))
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is NOT Bipartite\n";

    return 0;
}
