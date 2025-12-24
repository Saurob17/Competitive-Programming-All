#include <bits/stdc++.h>
using namespace std;

void TopoSortDFS(vector<vector<int>> &adj, vector<bool> &vis, int source, stack<int> &st)
{
    vis[source] = true;

    for (auto node : adj[source])
    {
        if (!vis[node])
        {
            TopoSortDFS(adj, vis, node, st);
        }
    }
    st.push(source);
}

int main()
{
    int Node, Edg;
    cin >> Node >> Edg;

    vector<vector<int>> adj(Node);   // CORRECT
    vector<bool> vis(Node, false);

    for (int i = 0; i < Edg; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st;
    for (int i = 0; i < Node; i++)
    {
        if (!vis[i])
        {
            TopoSortDFS(adj, vis, i, st);
        }
    }

    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }

  
    for (auto x : topo) cout << x << " ";
}
