#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
priority_queue<int> pq;
vector<int> vis;
vector<int> ans;
vector<int>inpq;

void dfs(int node)
{
    if (vis[node] )
        return;

    vis[node] = 1;
    ans.push_back(node);
    for (auto it : adj[node])
    {
        if (vis[it] == 0 && !inpq[it])
        {
            inpq[it]=1;
            int nod=(-1)*it;
            pq.push(nod);
        }
    }
    while (!(pq.empty()))
    {
        /* code */ 
        int nd = pq.top() * (-1);
        pq.pop();
        dfs(nd);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    inpq.resize(n+2,0);
    adj.resize(n+2);
    vis.resize(n+2, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(auto it:ans){
        cout<<it<<" ";
    }
}