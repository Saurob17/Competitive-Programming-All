#include<bits/stdc++.h>
using namespace std;
vector<int>rnk, parent;
void makeSet(int n) {
    rnk.resize(n + 1, 1);
    parent.resize(n + 1);
    for (int i = 1;i <= n;i++) {
        parent[i] = i;
    }
}
int findParent(int v) {
    if (parent[v] == v)return v;
    return parent[v] = findParent(parent[v]);
}
void rankUnion(int u, int v) {
    u = findParent(u);
    v = findParent(v);

    if (rnk[v] > rnk[u])swap(v, u);
    parent[v] = u;
    if (rnk[v] == rnk[u])rnk[u]++;

}
int main() {
    int v, e, op;
    cin >> v >> e >> op;
    for (int i = 0;i < e;i++) {
        int u, v;
        cin >> u >> v;

    }
    makeSet(op);
    vector<int>U(op), V(op);
    vector<string>typ(op);

    for (int i = 0;i < op;i++) {
        int u, v, o;
        cin >> typ[i] >> U[i] >> V[i];
    }

    vector<string>ans;
    for (int i = op - 1;i >= 0;i--) {
        if (typ[i] == "ask") {
            int u = findParent(U[i]);
            int v = findParent(V[i]);
            if (u == v) {
                ans.push_back("YES");
            }
            else {
                ans.push_back("NO");
            }
        }
        else {
            rankUnion(U[i], V[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto it : ans) {
        cout << it <<endl;
    }

}