#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
int parent[MAXN];
int dist[MAXN];
int findSet(int v) {
    if (parent[v] == v)return v;
    int root = findSet(parent[v]);
    dist[v] += dist[parent[v]];
    return parent[v] = root;
}
int  main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        parent[i] = i;
    }

    while (m--) {
        int q;
        cin >> q;
        if (q == 1) {
            int a, b;
            cin >> a >> b;
            parent[a] = b;
            dist[a] = 1;
        }
        else {
            int c;
            cin >> c;
            findSet(c);
            cout << dist[c] << "\n";

        }
    }

}