#include <bits/stdc++.h>
using namespace std;

bool isCycleUndiGraBFS(vector<vector<int>>& adj, int source, vector<bool>& vis) {
    vis[source] = true;
    queue<pair<int,int>> qe; // {node, parent}
    qe.push({source, -1});

    while (!qe.empty()) {
        auto it = qe.front();
        qe.pop();

        int node = it.first;
        int parent = it.second;

        for (auto nbr : adj[node]) {
            if (!vis[nbr]) {
                vis[nbr] = true;
                qe.push({nbr, node});
            }
            // IF visited neighbor is not parent → CYCLE FOUND
            else if (nbr != parent) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int node, edg;
    cin >> node >> edg;

    vector<vector<int>> adj(node);
    for (int i = 0; i < edg; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(node, false);

    // Graph may be disconnected, so check each component
    for (int i = 0; i < node; i++) {
        if (!vis[i]) {
            if (isCycleUndiGraBFS(adj, i, vis)) {
                cout << "Cycle Found\n";
                return 0;
            }
        }
    }

    cout << "No Cycle\n";
    return 0;
}
