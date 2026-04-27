#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &it:v){
        cin>>it;
    }

    int l=0,r=0;
    int ans=1,co=0;
    set<int>s;
    while (r<n && l<=r)
    {
        /* code */
        int x=v[r];
        if(!s.empty() && s.find(x)!=s.end()){
            while(1){

                int y=v[l];
                if(x==y){
                    l++;
                    r++;
                    break;
                }
                s.erase(y);
                co--;
                l++;
            }
        }
        else{
            s.insert(x);
            r++;
            co++;
        }
        ans=max(ans,co);
       // cout<<x<<"  ";
    }
    cout<<endl;
    cout<<ans;
    
}