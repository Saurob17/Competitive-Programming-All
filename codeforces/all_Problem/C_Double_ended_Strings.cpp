#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
//longerst common substring
    while(t--){
            string a,b;
            cin>>a>>b;

            int n=a.size();
            int m=b.size();

            int dp[n+1][m+1];
            memset(dp,0,sizeof(dp));

            int ans=0;

            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(a[i-1]==b[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                        ans=max(ans,dp[i][j]);  
                    }
                }
            }
            cout<<(m+n)-ans*2<<endl;
         

    }
}