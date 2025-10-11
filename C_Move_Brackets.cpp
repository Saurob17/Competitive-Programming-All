#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        int clo=0,op=0;

        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                op++;
            }
            else{
                clo++;
            }
            mx=max(mx,clo-op);
        }
        if(mx<0){
            cout<<0<<endl;
        }
        else{
                cout<<mx<<endl;
        }
    

    }
}