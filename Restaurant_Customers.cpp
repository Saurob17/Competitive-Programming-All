#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin>>n;
    n+=5;
    vector<int>v(n,0);

    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        v[l]+=1;
        v[r+1]-=1;
    }
    int ans=0;

    for(int i=1;i<=n;i++){
        v[i]+=v[i-1];
        ans=max(ans,v[i]);
    }
    cout<<ans;
   
}