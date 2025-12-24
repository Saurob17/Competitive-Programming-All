#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}

void dfs1(int node, vector<int> &vis, vector<vector<int>> &adjT)
{
    vis[node] = 1;
    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            dfs1(it, vis, adjT);
        }
    }
}

int Kosaraju(int v, vector<vector<int>> &adj)
{
    vector<int> vis(v, 0);
    stack<int> st;

    // Step 1: order by finishing time
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }

    // Step 2: transpose graph
    vector<vector<int>> adjT(v);
    for (int i = 0; i < v; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    // Step 3: DFS on transpose
    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!vis[node])
        {
            scc++;
            dfs1(node, vis, adjT);
        }
    }

    return scc;
}

int main()
{
    int v = 5;
    vector<vector<int>> adj(v);

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);

    cout << "Number of SCC = " << Kosaraju(v, adj) << endl;
}
