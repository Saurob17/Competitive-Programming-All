#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<int> uu(M), vv(M);
    for (int i = 0; i < M; ++i) {
        cin >> uu[i] >> vv[i];
        --uu[i]; --vv[i];
    }

   
    if (N <= 25) {
        int limit = 1 << N;
        vector<unsigned long long> adj(N, 0ULL);
        for (int i = 0; i < M; ++i) {
            adj[uu[i]] |= (1ULL << vv[i]);
            adj[vv[i]] |= (1ULL << uu[i]);
        }
        vector<int> dp(limit, 0); 
        for (int mask = 1; mask < limit; ++mask) {
            int lb = mask & -mask;
            int idx = __builtin_ctz(mask);
            int prev = mask ^ lb;
            dp[mask] = dp[prev] + __builtin_popcountll(adj[idx] & (unsigned long long)prev);
        }

        int bestCut = 0;
        int full = limit - 1;
        for (int mask = 0; mask < limit; ++mask) {
            int comp = full ^ mask;
            int internal = dp[mask] + dp[comp];
            int cut = M - internal;
            if (cut > bestCut) bestCut = cut;
        }
        cout << (M - bestCut) << '\n';
        return 0;
    }

 
    int limit = 1 << N;
    int best = 0;
    for (int mask = 0; mask < limit; ++mask) {
        int cnt = 0;
        for (int i = 0; i < M; ++i) {
            int a = (mask >> uu[i]) & 1;
            int b = (mask >> vv[i]) & 1;
            if (a != b) ++cnt;
        }
        best = max(best, cnt);
    }
    cout << (M - best) << '\n';
    return 0;
}
