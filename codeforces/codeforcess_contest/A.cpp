#include<bits/stdc++.h>
using namespace std;
int  main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());

        bool inPoss=true;
        for(int i=1;i<=n-1;i++){
            if(i%2==0){
                if(a[i]!=a[i+1]){
                    inPoss=false;
                    break;
                }
            }
        }
        if(inPoss){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}