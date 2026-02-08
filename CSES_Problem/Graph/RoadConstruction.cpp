#include<bits/stdc++.h>
using namespace std;
vector<int>rnk, parent, compon;
void makeset(int n) {
    rnk.resize(n + 1, 0);
    parent.resize(n + 1);
    compon.resize(n + 1, 1);
    for (int i = 1;i <= n;i++) {
        parent[i] = i;
    }
}
int findPath(int v) {
    if (parent[v] == v)return v;
    return parent[v] = findPath(parent[v]);
}
vector<int>rankUnion(int u, int v) {
    vector<int>res;

    u = findPath(u);
    v = findPath(v);
    res.push_back(u);
    res.push_back(v);

    int u1 = u, v1 = v;
    if (u != v) {
        if (rnk[v] > rnk[u])swap(u, v);
        parent[v] = u;
        if (rnk[u] == rnk[v])rnk[u]++;
    }
    if (u == v)res.push_back(0);
    else {
        res.push_back(1);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int node, edg;
    cin >> node >> edg;
    makeset(node);
    int mx = 1;
    int com = node;
    for (int i = 0;i < edg;i++) {
        int u, v;
        cin >> u >> v;

        vector<int>res = rankUnion(u, v);

        if (res[2] == 0) {
            cout << com << " " << mx << endl;
        }
        else {
            mx = max(mx, (compon[res[0]] + compon[res[1]]));
            if (rnk[res[0]] >= rnk[res[1]]) {
                compon[res[0]] = compon[res[0]] + compon[res[1]];

            }
            else {
                compon[res[1]] = compon[res[0]] + compon[res[1]];
            }
            com--;
            cout << com << " " << mx << endl;
        }
    }

}