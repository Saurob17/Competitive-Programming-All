#include<bits/stdc++.h>
int n,m;
 int r,c,r2,c2;
using namespace std;
    void dfs(vector<vector<int>>&arr,int i,int j){
        arr[i][j]++;

        if(arr[i][j]>1)return;

        if(i+1<n && arr[i+1][j]<2){
            dfs(arr,i+1,j);
        }
        if(i-1>=0 && arr[i-1][j]<2){
            dfs(arr,i-1,j);
        }
        if(j+1<m && arr[i][j+1]<2){
            dfs(arr,i,j+1);
        }

         if(j-1>=0 && arr[i][j-1]<2){
            dfs(arr,i,j-1);
        }
    }


int main(){
    
    cin>>n>>m;
   vector<vector<int>>arr(n);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin>>c;
            if(c=='.')arr[i].push_back(0);
            else{
              arr[i].push_back(1);
            }
        }
    }
    
    
    cin>>r>>c>>r2>>c2;
   
r--; c--; r2--; c2--;

    arr[r][c]=0;

    dfs(arr,r,c);

    if(arr[r2][c2]>1){
        cout<<"YES";
    }
    else{
        cout<<"NO"; 
    }

}