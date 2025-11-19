#include<bits/stdc++.h>
using namespace std;
int right_low_valuecount(int index,int value,vector<int> &a){
    int count=0;
    for(int i=index+1;i<a.size();i++){
        if(a[i]<value) count++;
    }
    return count;
   
}
int left_low_valuecount(int index,int value,vector<int> &a){
    int count=0;
    for(int i=index-1;i>=0;i--){
        if(a[i]<value) count++;
    }
    return count;
   
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
    
        int ans=0;

        for(int i=0;i<n;i++){
            int right_count=right_low_valuecount(i,a[i],a);
            int left_count=left_low_valuecount(i,a[i],a);
           
            ans+=min(left_count,right_count);
        }
        cout<<ans<<endl;


        
        
    }
}