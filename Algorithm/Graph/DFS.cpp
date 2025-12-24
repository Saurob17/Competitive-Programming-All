#include <bits/stdc++.h>
using namespace std;
void DFS(vector<int>adj[], int source, vector<int> &dfs, vector<int> &vis)
{
    vis[source] = 1;
    dfs.push_back(source);
    for (auto it : adj[source])
    {
        if (!vis[it])
        {
            DFS(adj, it, dfs, vis);
        }
    }
}
void DFS_it(vector<int>adj[], int source, vector<int> &dfs, vector<int> &vis){
    vis[source]=1;
    stack<int>st;
    st.push(source);

    while(!st.empty()){
        int tp=st.top();
        st.pop();
        vis[tp]=1;
        
                dfs.push_back(tp);
        for(auto it:adj[tp]){
            if(!vis[it]){
                st.push(it);
                vis[it]=1;
            }
        }
    }

}
int main()
{
   int Node, Edg;
    cin >> Node >> Edg;
    vector<int> adj[Node + 1];
    vector<int> dfs;
    vector<int> vis(Node + 1, 0);

    for (int i = 0; i < Edg; i++)
       
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    DFS_it(adj,1,dfs,vis);

    for (int it : dfs)
    {
        cout << it << " ";
    }
}

