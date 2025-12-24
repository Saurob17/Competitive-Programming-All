#include <bits/stdc++.h>
using namespace std;

// Prim's MST function
int primMST(int Node, vector<vector<pair<int,int>>>& adj) {

    vector<int> vis(Node, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 0}); // {wt, node}
    int sum = 0;

    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int wt = it.first;

        if(vis[node]) continue;

        vis[node] = 1;
        sum += wt;

        for(auto next : adj[node]) {
            int adjNode = next.first;
            int edW = next.second;

            if(!vis[adjNode]) {
                pq.push({edW, adjNode});
            }
        }
    }

    return sum;
    
}

pair<int, vector<pair<int,int>>> primMST_Tree(int Node, vector<vector<pair<int,int>>>& adj) {

    vector<int> vis(Node, 0);
    vector<int> parent(Node, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 0}); // {wt, node}
    int sum = 0;

    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int wt = it.first;

        if(vis[node]) continue;
        vis[node] = 1;
        sum += wt;

        for(auto next : adj[node]) {
            int adjNode = next.first;
            int edW = next.second;

            if(!vis[adjNode]) {
                pq.push({edW, adjNode});
                parent[adjNode] = node;   // ⬅️ MST edge track
            }
        }
    }

    // Build MST edges list
    vector<pair<int,int>> mstEdges;
    for(int i = 1; i < Node; i++) {
        if(parent[i] != -1)
            mstEdges.push_back({parent[i], i});
    }

    return {sum, mstEdges};
}

int main() {

    int Node, Edg;
    cin >> Node >> Edg;

    // adjacency list: adj[node] = { {adjNode, weight}, ... }
    vector<vector<pair<int,int>>> adj(Node);

    for (int i = 0; i < Edg; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // Undirected Graph for MST
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int result = primMST(Node, adj);

    cout << "Total Weight of MST = " << result << endl;

    return 0;
}
