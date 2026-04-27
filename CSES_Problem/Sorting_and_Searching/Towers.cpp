#include<bits/stdc++.h>
using namespace std;
int  main(){
    int n;
    cin>>n;
    multiset<int>s;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(!s.empty()){
            auto it=s.upper_bound(x);
            if(it!=s.end()){
                s.erase(it);
                s.insert(x);
            }
            else{
                s.insert(x);
            }
        }
        else{
            s.insert(x);
        }
    }
    cout<<s.size();


}