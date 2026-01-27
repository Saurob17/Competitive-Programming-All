#include <bits/stdc++.h>
using namespace std;

vector<bool> vis(1e5,false);
map<int, int> m, mp;
void dfs(vector<vector<int>> &adj, int node, int col)
{
    vis[node] = true;
    mp[node] = col;
    m[col]++;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(adj, it, 1 - col);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n+1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj, 1, 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mp[i] == 0)
        {
            ans += (m[1] - adj[i].size());
        }
    }

    cout << ans;
}