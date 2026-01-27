#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int tin[100005], tout[100005];
int timer = 0;

void dfs(int u, int parent)
{
    tin[u] = ++timer;

    for (int v : adj[u])
    {
        if (v == parent) continue;
        dfs(v, u);
    }

    tout[u] = timer;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    return 0;
}
