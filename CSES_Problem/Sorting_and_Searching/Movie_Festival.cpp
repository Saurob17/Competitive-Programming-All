#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> p;
    for(int i=0;i<n;i++){
        int st,ed;
        cin>>st>>ed;
        p.push_back({ed,st});
    }
    sort(p.begin(),p.end());    
    int ans=1;
    int cend=p[0].first;
    for(int i=0;i<n-1;i++){
        if(cend<=p[i+1].second){
            cend=p[i+1].first;
            ans++;
        }
    }

    cout<<ans++;
}