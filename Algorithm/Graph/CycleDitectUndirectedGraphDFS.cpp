#include<bits/stdc++.h>
using namespace std;

bool isCycleUndiGraDFS(int source, int parent, vector<vector<int>>& adj, vector<bool>& vis){
    vis[source] = true;

    for(auto it: adj[source]){
        if(!vis[it]){
            if(isCycleUndiGraDFS(it, source, adj, vis)) 
                return true;
        }
        else if(it != parent){
            return true;  // Back edge → cycle
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

    for (int i = 0; i < node; i++) {
        if (!vis[i]) {
            if(isCycleUndiGraDFS(i, -1, adj, vis)){
                cout << "Cycle Found\n";
                return 0;
            }
        }
    }
    
    cout << "No Cycle\n";
    return 0;
}
