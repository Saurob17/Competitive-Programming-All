#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;

    vector<int>v(n);
    for(auto &it:v){
        cin>>it;
    }

    sort(v.begin(),v.end());
    int l=0,r=n-1;
    int ans=0;
    while(l<=r){
        if((v[l]+v[r])<=x){
            l++;
            r--;
            ans++;
        }
        else if(v[r]<=x){
            ans++;
            r--;
        }
        else{
            r--;
        }
    }
    cout<<ans;

}