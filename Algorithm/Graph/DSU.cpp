
#include <bits/stdc++.h>
using namespace std;

vector<int> ran, parent;
void makeSet(int n)
{
    parent.resize(n + 1);
    ran.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
        parent[i] = i;
}

int findParent(int node)
{
    if (node == parent[node])
        return node;
    return parent[node] = findParent(parent[node]);
}
void UnionByRank(int u, int v)
{
    int ulp_u = findParent(u);
    int ulp_v = findParent(v);

    if (ulp_u == ulp_v)
        return;

        if(ran[ulp_u]<ulp_v){
            parent[ulp_u]=ulp_v;
        }
       else if(ran[ulp_u]>ran[ulp_v]) {
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            ran[ulp_u]++;
        }

}

int main()
{
     ios::sync_with_stdio(false);
    cin.tie(nullptr);
    makeSet(5);
    UnionByRank(2,3);
    UnionByRank(4,5);
    UnionByRank(5,6);
    UnionByRank(6,2);
}
