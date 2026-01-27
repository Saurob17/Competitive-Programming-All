// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     map<pair<int,int>, int> cost;
//     vector<vector<int>> adj(n + 1);

//     for (int i = 0; i < n; i++) {
//         int a, b, c;
//         cin >> a >> b >> c;
//         cost[{a, b}] = c;

//         // undirected adjacency for cycle reconstruction
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }

//     // reconstruct the cycle
//     vector<int> cycle;
//     vector<bool> vis(n + 1, false);

//     int start = 1;
//     int prev = -1, cur = start;

//     while (true) {
//         cycle.push_back(cur);
//         vis[cur] = true;

//         int next = -1;
//         for (int x : adj[cur]) {
//             if (x != prev) {
//                 next = x;
//                 break;
//             }
//         }

//         if (next == start) break;
//         prev = cur;
//         cur = next;
//     }

//     long long cw = 0, ccw = 0;
//     int sz = cycle.size();

//     for (int i = 0; i < sz; i++) {
//         int u = cycle[i];
//         int v = cycle[(i + 1) % sz];

//         // clockwise u -> v
//         if (!cost.count({u, v}))
//             cw += cost[{v, u}];

//         // counter-clockwise v -> u
//         if (!cost.count({v, u}))
//             ccw += cost[{u, v}];
//     }

//     cout << min(cw, ccw) << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    map<pair<int, int>, int> mp;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u, v}] = c;
    }

    vector<int> cycle;
    int pre = -1, curr = 1, start = 1;

    while (1)
    {
        cycle.push_back(curr);
        for (auto it : adj[curr])
        {
            if (it != pre)
            { 
                 pre = curr;
                curr = it;
              
                break;
            }
        }
        if (curr == start)
        {
            break;
        }
    }

    int cw = 0, ccw = 0;

    int sz = cycle.size();
    for (int i = 0; i < sz; i++)
    {
        int u = cycle[i], v = cycle[(i + 1) % sz];
        if (!mp.count({u, v}))
        {
            cw += mp[{v, u}];
        }
        if (!mp.count({v, u}))
        {
            ccw += mp[{u, v}];
        }
    }
    cout<<min(ccw,cw);
}