//https://leetcode.com/problems/counting-bits/description/
#include<bits/stdc++.h>
using namespace std;

void countBits(int n,vector<int>&ans){

    ans[0]=0;

    for(int i=1;i<=n;i++){
        ans[i]=ans[i>>1]+(i&1);// that means if last bit is 1 then add 1 else 0 and i<<1 is equivalent to i/2
        //ans[i]=ans[i/2]+(i%2); // alternative
    }
}
int main(){

    int n;
    cin>>n;
    vector<int>ans(n+1,0);
    countBits(n,ans);

    for(int i=0;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}