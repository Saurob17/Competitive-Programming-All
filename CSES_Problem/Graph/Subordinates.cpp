#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200001];
int sub[200001];

int dfs(int u){
    int cnt = 0;
    for(int v : adj[u]){
        cnt += dfs(v) + 1;
    }
    return sub[u] = cnt;
}

int main(){
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++){
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }

    dfs(1);

    for(int i = 1; i <= n; i++){
        cout << sub[i] << " ";
    }
}
