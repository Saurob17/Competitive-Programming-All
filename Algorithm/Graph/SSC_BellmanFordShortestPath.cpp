#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int src)
{
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    // N-1 relaxations
    for (int i = 0; i < V - 1; i++)
    {
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Nth iteration → detect negative cycle
    for (auto &e : edges)
    {
        int u = e[0];
        int v = e[1];
        int wt = e[2];

        if (dist[u] != 1e8 && dist[u] + wt < dist[v])
        {
            return {-1}; // negative cycle exists
        }
    }

    return dist;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;
    cin >> src;

    vector<int> ans = bellman_ford(V, edges, src);

    if (ans.size() == 1 && ans[0] == -1)
    {
        cout << "Negative cycle detected\n";
    }
    else
    {
        for (int i = 0; i < V; i++)
        {
            if (ans[i] == 1e8)
                cout << "INF ";
            else
                cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
