#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    vector<int>v(n);
    for(auto &it:v){
        cin>>it;
    }


    long long ans=-1e18;
    long long total=0;
    for(int i=0;i<n;i++){
        total+=v[i];
        ans=max(ans,total);
        if(total<1)total=0;
    }
    
    cout<<ans;

}