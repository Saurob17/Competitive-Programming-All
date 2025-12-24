#include<bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> adj[], int source, int N) {

    set<pair<int,int>> st; // {distance, node}
    vector<int> dis(N, 1e9);

    dis[source] = 0;
    st.insert({0, source});

    while(!st.empty()) {
        auto it = *st.begin();
        st.erase(st.begin());

        int wt = it.first;
        int node = it.second;

        for(auto edge : adj[node]) {
            int dist = edge[0];     // weight
            int adjNode = edge[1];  // neighbor

            if(wt + dist < dis[adjNode]) {

                if(dis[adjNode] != 1e9) {
                    st.erase({dis[adjNode], adjNode});
                }

                dis[adjNode] = wt + dist;
                st.insert({dis[adjNode], adjNode}); 
            }
        }
    }

    return dis;
}

int main(){

}