#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; if(!(cin>>t)) return 0;
    while(t--){
        int n; cin>>n;
        vector<int>a1(n+1),a2(n+1);
        for(int i=1;i<=n;i++) cin>>a1[i];
        for(int i=1;i<=n;i++) cin>>a2[i];
        vector<int> prefMin(n+1), prefMax(n+1), suffMin(n+2), suffMax(n+2);
        const int INF = 1e9+5;
        prefMin[0]=INF; prefMax[0]=0;
        for(int i=1;i<=n;i++){ prefMin[i]=min(prefMin[i-1], a1[i]); prefMax[i]=max(prefMax[i-1], a1[i]); }
        suffMin[n+1]=INF; suffMax[n+1]=0;
        for(int i=n;i>=1;i--){ suffMin[i]=min(suffMin[i+1], a2[i]); suffMax[i]=max(suffMax[i+1], a2[i]); }
        vector<pair<int,int>> segs; segs.reserve(n);
        for(int k=1;k<=n;k++){
            int mn = min(prefMin[k], suffMin[k]);
            int mx = max(prefMax[k], suffMax[k]);
            segs.emplace_back(mn,mx);
        }
        sort(segs.begin(), segs.end(), [](auto &p, auto &q){ return p.first > q.first; });
        long long ans=0;
        int ptr=0; int M=2*n; int curMinMx = INT_MAX; // minimal mx among segs with mn>=l
        for(int l=M;l>=1;l--){
            while(ptr<(int)segs.size() && segs[ptr].first>=l){
                curMinMx = min(curMinMx, segs[ptr].second);
                ++ptr;
            }
            if(curMinMx!=INT_MAX){
                ans += (long long)(M - curMinMx + 1);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
