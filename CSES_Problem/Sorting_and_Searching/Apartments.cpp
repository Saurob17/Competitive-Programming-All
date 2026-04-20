#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;

    multiset<long long>st;
    vector<int>v(n);

    for(auto &it:v){
        cin>>it;
    }

    for(int i=0;i<m;i++){
        long long  x;
        cin>>x;
        st.insert(x);

    }
    sort(v.begin(),v.end());
    int ans=0;

    for(auto it:v){
        long long lo=it-k,hi=it+k;

        auto itl=st.lower_bound(lo);

        if( itl !=st.end() &&  *itl<=hi){
            ans++;
            st.erase(itl);
        }
        if(st.empty()){
            break;
        }
    }
    cout<<ans;
}