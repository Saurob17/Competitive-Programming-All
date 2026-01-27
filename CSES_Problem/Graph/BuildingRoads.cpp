#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
bool vis[100001];

void dfs(int node) {
    vis[node] = true;
    for(int nxt : adj[node]) {
        if(!vis[nxt]) dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> representatives;

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            representatives.push_back(i);
            dfs(i);
        }
    }

    cout << representatives.size() - 1 << "\n";

    for(int i = 1; i < representatives.size(); i++) {
        cout << representatives[i-1] << " " << representatives[i] << "\n";
    }

    return 0;
}
