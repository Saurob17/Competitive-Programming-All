#include <bits/stdc++.h>
using namespace std;
vector<bool> vis(1e5);
int mx;
void dfs(int node, int nmx, vector<vector<pair<int, int>>> &adj)
{
    vis[node] = true;
    for (auto chaild : adj[node])
    {
        if (!vis[chaild.first])
        {
            dfs(chaild.first, nmx + chaild.second, adj);
        }
    }
    mx = max(mx, nmx);
}
int main()
{
    mx = 0;
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < n; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[v].push_back({u, c});
         adj[u].push_back({v, c});
    }
    dfs(0, 0, adj);
    cout << mx;
}