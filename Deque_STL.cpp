#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

   
   int n;
   cin>>n;
   int mx=INT_MIN;
   vector<string>v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
    int l=v[i].size();
    mx=max(l,mx);
   }
   for(int i=0;i<n;i++){
    int ln=v[i].size();
    int lo=(mx-ln)/2;
    for(int j=1;j<=lo;j++){
        cout<<'.';
    }
    cout<<v[i];
    for(int j=1;j<=lo;j++){
        cout<<'.';
    }
    cout<<endl;
   }
    
}