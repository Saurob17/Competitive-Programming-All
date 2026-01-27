#include <bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>> &adj, vector<int> &dist)
{
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> distA(n + 1, -1), distB(n + 1, -1);

    bfs(1, adj, distA);   // Alice
    bfs(x, adj, distB);   // Bob

    int best = 0;

    for (int i = 1; i <= n; i++)
    {
        if (distB[i] < distA[i])
        {
            best = max(best, distA[i]);
        }
    }

    cout << best * 2 << "\n";

    return 0;
}
