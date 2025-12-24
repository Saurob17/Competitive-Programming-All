#include<bits/stdc++.h>
using namespace std;
//finde bridge in graph
int timer=1;
   void dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj,
             int tin[], int low[], vector<vector<int>>& bridge) {

        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node]) {
            if (it == parent) {
                continue;
            }
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridge);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node]) {
                    bridge.push_back({it, node});
                }
            } else {
                low[node] = min(low[node], low[it]);
            }
        }
    }

int main(){
  int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
vector<int>vis(n,0);
int tin[n];
int low[n];
vector<vector<int>>bridge;
dfs(0,-1,vis,adj,tin,low,bridge);


}