#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    multiset<int> st;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.insert(x);
    }

    for(int i=0;i<m;i++){

        int x;
        cin>>x;

        auto it = st.upper_bound(x);

        if(it==st.begin()){
            cout<<-1<<"\n";
        }
        else{
            it--;
            cout<<*it<<"\n";
            st.erase(it);
        }
    }
}