#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007; // single hash
const ll P = 31;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, good;
    int k;
    cin >> s >> good >> k;

    int n = s.size();

    // Prefix sum of bad letters
    vector<int> bad(n+1,0);
    for(int i=0;i<n;i++){
        int idx = s[i]-'a';
        if(good[idx]=='0') bad[i+1] = 1;
    }
    for(int i=1;i<=n;i++) bad[i] += bad[i-1];

    // Precompute powers
    vector<ll> powP(n+1,1);
    for(int i=1;i<=n;i++) powP[i] = (powP[i-1]*P)%MOD;

    // Prefix hash
    vector<ll> h(n+1,0);
    for(int i=0;i<n;i++){
        h[i+1] = (h[i]*P + (s[i]-'a'+1))%MOD;
    }

    auto getHash = [&](int l,int r){
        return (h[r] - h[l]*powP[r-l]%MOD + MOD)%MOD;
    };

    // Store distinct good substrings
    set<ll> st;
    for(int l=0;l<n;l++){
        for(int r=l+1;r<=n;r++){
            int bad_count = bad[r]-bad[l];
            if(bad_count<=k){
                st.insert(getHash(l,r));
            }
        }
    }

    cout << st.size() << "\n";
    return 0;
}
