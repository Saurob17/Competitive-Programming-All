#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;
const ll BASE = 911382323; // বড় random base নেয়া ভালো

vector<ll> pow1, pow2, hash1, hash2;

// Precompute powers
void precompute(int n) {
    pow1.assign(n+1,1);
    pow2.assign(n+1,1);
    for(int i=1;i<=n;i++){
        pow1[i] = (pow1[i-1]*BASE) % MOD1;
        pow2[i] = (pow2[i-1]*BASE) % MOD2;
    }
}

// Build prefix hashes for string
void buildHash(const string &s) {
    int n = s.size();
    hash1.assign(n+1,0);
    hash2.assign(n+1,0);
    for(int i=0;i<n;i++){
        hash1[i+1] = (hash1[i]*BASE + s[i]) % MOD1;
        hash2[i+1] = (hash2[i]*BASE + s[i]) % MOD2;
    }
}

// Get hash of substring [l,r] (1-indexed)
pair<ll,ll> getHash(int l,int r) {
    ll x1 = (hash1[r] - hash1[l-1]*pow1[r-l+1] % MOD1 + MOD1) % MOD1;
    ll x2 = (hash2[r] - hash2[l-1]*pow2[r-l+1] % MOD2 + MOD2) % MOD2;
    return {x1,x2};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;
    cin >> text >> pattern;
    int n = text.size(), m = pattern.size();

    precompute(max(n,m));
  //  buildHash(text);

    // Compute hash of pattern
    buildHash(pattern);
    auto patternHash = getHash(1,m);

    // Rebuild text hash (important)
    buildHash(text);

    int count = 0;
    for(int i=1;i+m-1<=n;i++){
        if(getHash(i,i+m-1) == patternHash)
            count++;
    }

    cout << count << "\n";
    return 0;
}
