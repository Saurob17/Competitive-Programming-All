#include <bits/stdc++.h>
using namespace std;

bool isBipartiteDFS(int node, int col,
                    vector<vector<int>> &adj,
                    vector<int> &color)
{
    color[node] = col;
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            if (!isBipartiteDFS(it, !col, adj, color))
                return false;
        }
        else if (color[it] == color[node])
        {
            return false;
        }
    }
    return true;
}

int main()
{
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

    vector<int> color(n, -1);
    bool ok = true;

    // handle disconnected graph
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!isBipartiteDFS(i, 0, adj, color))
            {
                ok = false;
                break;
            }
        }
    }

    if (ok)
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is NOT Bipartite\n";

    return 0;
}
