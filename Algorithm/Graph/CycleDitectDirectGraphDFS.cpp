#include <bits/stdc++.h>
using namespace std;

bool isCycleDirectGraphDFS(int node, vector<vector<int>> &adj,
                           vector<bool> &vis, vector<bool> &path)
{
    vis[node] = true;
    path[node] = true;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (isCycleDirectGraphDFS(it, adj, vis, path))
            {

                return true;
            }
        }
        else if (path[it])
        {
            return true;
        }
    }

    path[node] = false;
    return false;
}
int main()
{
    int node, edg;
    cin >> node >> edg;

    vector<vector<int>> adj(node);
    for (int i = 0; i < edg; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<bool> vis(node, false);
     vector<bool> path(node, false);


    // Graph may be disconnected, so check each component
    for (int i = 0; i < node; i++)
    {
        if (!vis[i])
        {
            if (isCycleDirectGraphDFS(i,adj,vis,path)) {
                cout << "Cycle Found\n";
                return 0;
            }
        }
    }

    cout << "No Cycle\n";
    return 0;
}