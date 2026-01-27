#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;
bool suspicious;

void dfs(int u)
{
    for (int v : adj[u])
    {
        if (color[v] == -1)
        {
            color[v] = 1 - color[u];
            dfs(v);
        }
        else if (color[v] == color[u])
        {
            suspicious = true;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int cnt = 1;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        adj.assign(n + 1, vector<int>());
        color.assign(n + 1, -1);
        suspicious = false;

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n && !suspicious; i++)
        {
            if (color[i] == -1)
            {
                color[i] = 0;
                dfs(i);
            }
        }

        cout << "Scenario #" << cnt++ << ":\n";
        if (suspicious)
            cout << "Suspicious bugs found!\n";
        else
            cout << "No suspicious bugs found!\n";
    }

    return 0;
}
