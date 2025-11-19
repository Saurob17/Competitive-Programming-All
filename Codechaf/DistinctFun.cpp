#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        unordered_set<int> seen;
        int ops = 0;
        for(int x : a){
            if(seen.count(x)){
                ++ops;
                seen.clear();
            }
            seen.insert(x);
        }
        cout << ops << '\n';
    }
}