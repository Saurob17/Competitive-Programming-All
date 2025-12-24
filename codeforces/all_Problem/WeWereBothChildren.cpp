#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
         unordered_map<int ,int>mp;
        set<int>v;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x<=n)
            {
                mp[x]++;
                
               v.insert(x);
            }
        }

        vector<int>ans((1e5*2)+2,0);
        int l=v.size();

        for(auto it:v){
            for(int j=it;j<=n;j+=it){
                ans[j]+=mp[it];
            }

        }

        int mx=*max_element(ans.begin(),ans.end());
        cout<<mx<<endl;


        
    }
    

}