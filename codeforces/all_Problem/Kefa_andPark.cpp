#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void dfs(vector<vector<int>> &adj, int m, int conCat, int node, vector<int> &v, int parent)
{
    if(v[node] == 1) conCat++;
    else conCat = 0;

    if(conCat > m) return;

    bool isLeaf = true;
    for(int child : adj[node]){
        if(child != parent){
            isLeaf = false;
            dfs(adj, m, conCat, child, v, node);
        }
    }

    if(isLeaf) cnt++;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> v(n + 1);
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (int i = 1; i < n; i++){
        int u, w;
        cin >> u >> w;
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    dfs(adj, m, 0, 1, v, 0);
    cout << cnt << endl;
}
