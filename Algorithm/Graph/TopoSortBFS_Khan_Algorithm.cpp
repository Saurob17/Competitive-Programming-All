#include <bits/stdc++.h>
using namespace std;

vector<int> toposortKahnBFS(vector<vector<int>> &adj, vector<int> indegree)
{
    int n = indegree.size();
    queue<int> q;
    vector<int> topo;

    // all indegree 0 nodes
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // BFS
    while (!q.empty())
    {
        int tp = q.front();
        q.pop();
        topo.push_back(tp);    // add to result

        for (auto nxt : adj[tp])
        {
            indegree[nxt]--;
            if (indegree[nxt] == 0)
            {
                q.push(nxt);
            }
        }
    }

    return topo;
}

int main()
{
    int node, edg;
    cin >> node >> edg;

    vector<vector<int>> adj(node);
    vector<int> indegree(node, 0);

    for (int i = 0; i < edg; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    vector<int> topo = toposortKahnBFS(adj, indegree);

    for (auto x : topo) cout << x << " ";
}
