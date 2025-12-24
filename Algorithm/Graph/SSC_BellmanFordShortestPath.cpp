//in bellman Ford Algorithm Exectly N-1 iteration
#include<bits/stdc++.h>
using namespace std;
vector<int>bellman_ford(int v,vector<vector<int>>&adj,int s){
    vector<int>dis(v,1e8);
dis[s]=0;
    for(int i=0;i<v-1;i++){
        for(auto it:adj){
            int u=it[0];
            int u=it[1];
            int wt=it[2];

            if(dis[u]!=1e8 && dis[u]+wt <dis[v]){
                dis[v]=dis[u]+wt;
            }

        }
    }
    //Nth iteration to check negative cycle

    for(auto it:adj){
          int u=it[0];
            int u=it[1];
            int wt=it[2];
            if(dis[u]!=1e8 && dis[u]+wt<dis[v]){
                return {-1};
            }
    }
    return dis;

}
int main(){
    
    int u,v;
    cin>>u>>v;
    vector<vector<int>>adj;
    

}