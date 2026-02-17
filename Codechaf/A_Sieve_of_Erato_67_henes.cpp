#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        map<int,int>mp;

        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            mp[x]=1;


        }
        if(mp[67]==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}