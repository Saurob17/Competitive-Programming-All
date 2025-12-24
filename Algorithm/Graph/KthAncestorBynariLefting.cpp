#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 20;   // 2^20 > 10^6 (safe)

vector<int> adj[MAXN];
int lift[MAXN][LOG];
int depth[MAXN];
int n;

void dfs(int node, int parent)
{
    lift[node][0] = parent;
    for (int i = 1; i < LOG; i++)
    {
        if (lift[node][i - 1] != -1)
            lift[node][i] = lift[lift[node][i - 1]][i - 1];
        else
            lift[node][i] = -1;
    }

    for (int child : adj[node])
    {
        if (child != parent)
        {
            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    }
}

int kthAncestor(int node, int k)
{
    for (int i = 0; i < LOG; i++)
    {
        if (k & (1 << i))
        {
            node = lift[node][i];
            if (node == -1)
                return -1;
        }
    }
    return node;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++)
        adj[i].clear();

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(lift, -1, sizeof(lift));

    int root = 1;     // root can be any node
    depth[root] = 0;
    dfs(root, -1);

    int q;
    cin >> q;
    while (q--)
    {
        int node, k;
        cin >> node >> k;
        cout << kthAncestor(node, k) << "\n";
    }

    return 0;
}
