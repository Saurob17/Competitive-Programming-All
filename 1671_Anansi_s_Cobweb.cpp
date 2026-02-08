#include<bits/stdc++.h>
using namespace std;
set<int>st;
vector<pair<int, int>>road;
vector<int>parent, rnk;
void reset(int n, int m) {
    road.resize(m + 1);
    parent.resize(n + 1);
    rnk.resize(n + 1,0);
    for (int i = 1;i <= n;i++)parent[i] = i,st.insert(i);
    
}
int findParent(int v)
{
    if (parent[v] == v)return v;
    return parent[v] = findParent(parent[v]);
}

void rnkeUnion(int u, int v) {
    u = findParent(u);
    v = findParent(v);
    if (u != v) {
        if (rnk[v] > rnk[u])swap(u, v);

        if (st.find(parent[v]) != st.end()) {
            st.erase(parent[v]);
        }

        parent[v] = u;

        if (rnk[u] == rnk[v]) {
            rnk[u]++;
        }
        if (st.find(parent[v]) != st.end()) {
            st.erase(parent[v]);
        }
        st.insert(u);

    }

}

int main() {
    int n, m;
    cin >> n >> m;
    reset(n,m);
    for (int i = 1;i <= m;i++) {
        cin >> road[i].first >> road[i].second;
    }
    int q;
    cin >> q;
    vector<int>rem(q + 1);
    vector<bool>remov(m + 1, false);
    for (int i = 1;i <= q;i++) {
        int x;
        cin >> rem[i];
        remov[rem[i]] = true;

    }

    for (int i = 1;i <= m;i++) {
        if (!remov[i]) {
            rnkeUnion(road[i].first, road[i].second);
        }
    }
    vector<int>ans;
    ans.push_back(st.size());
    while (q > 1)
    {
        rnkeUnion(road[rem[q]].first, road[rem[q]].second);
        ans.push_back(st.size());
        q--;

    }
    reverse(ans.begin(), ans.end());
    for (auto it : ans) {
        cout << it <<" ";

    }

}