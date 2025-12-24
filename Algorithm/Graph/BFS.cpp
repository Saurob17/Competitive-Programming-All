#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int start, int n, vector<int> adj[]) 
{
    vector<int> vis(n, 0);
    vector<int> bfs;
    queue<int> q;

    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (int child : adj[node]) {
            if (!vis[child]) {
                vis[child] = 1;
                q.push(child);
            }
        }
    }
    return bfs;
}
//0/1 BFS
vector<int> zeroOneBFS(int n, vector<pair<int,int>> adj[]) 
{
    deque<int> dq;
    vector<int> dist(n, INT_MAX);

    dist[0] = 0;
    dq.push_back(0);

    while (!dq.empty()) 
    {
        int node = dq.front();
        dq.pop_front();

        for (auto it : adj[node]) 
        {
            int next = it.first;
            int wt = it.second;

            // যদি নতুন পথ ছোট হয়
            if (dist[node] + wt < dist[next]) 
            {
                dist[next] = dist[node] + wt;

                if (wt == 0)
                    dq.push_front(next);   // 0-weight → সামনে
                else
                    dq.push_back(next);    // 1-weight → পেছনে
            }
        }
    }

    return dist;
}
//multi source bfs

vector<int> multiSourceBFS(int n, vector<int> adj[], vector<int> sources) {
    vector<int> dist(n, INT_MAX);
    queue<int> q;

    // Step 1: সব source একসাথে queue তে push
    for (int s : sources) {
        dist[s] = 0;
        q.push(s);
    }

    // Step 2: Normal BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto next : adj[node]) {
            if (dist[next] > dist[node] + 1) {
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }

    return dist;
}
//2nd multi source bfs
// vector < int > graph[MX];
// bool vis[MX];
// int dist[MX];

// void bfs(vector<int> sources){
//     queue < int > Q;
//     // initialization
//     for (int i = 0; i < sources.size(); i++){
//         int source = sources[i];
//         vis[source] = 1;
//         dist[source] = 0;
//         Q.push(source);
//     }

//     while(!Q.empty()){
//         int node = Q.front();
//         Q.pop();

//         for (int i = 0; i < graph[node].size(); i++){
//             int next = graph[node][i];
//             if (vis[next] == 0){
//                 vis[next] = 1; // visit
//                 dist[next] = dist[node] + 1; // update
//                 Q.push(next); // push to queue
//             }
//         }
//     }
// }


int main() 
{
    int node, edg;
    cin >> node >> edg;

    vector<int> adj[node];

    for (int i = 0; i < edg; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> ans = BFS(0, node, adj);

    for (int x : ans) cout << x << " ";
}
