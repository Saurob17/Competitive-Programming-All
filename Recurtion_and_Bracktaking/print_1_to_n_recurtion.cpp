#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int N; cin >> N;
        vector<int> a1(N), a2(N);
        for (int i = 0; i < N; ++i) cin >> a1[i];
        for (int i = 0; i < N; ++i) cin >> a2[i];

        vector<int> small(N), big(N);
        for (int i = 0; i < N; ++i) {
            small[i] = min(a1[i], a2[i]);
            big[i] = max(a1[i], a2[i]);
        }

        // prefix DP: okSmall[i] = possible to arrange cols [0..i] so that top at i = small[i]
        // okBig[i]   = possible to arrange cols [0..i] so that top at i = big[i]
        vector<char> okSmall(N, 0), okBig(N, 0);
        okSmall[0] = 1; okBig[0] = 1;
        for (int i = 1; i < N; ++i) {
            bool s = false, b = false;
            if (okSmall[i-1]) {
                if (small[i] >= small[i-1]) s = true;
                if (big[i] >= small[i-1]) b = true;
            }
            if (okBig[i-1]) {
                if (small[i] >= big[i-1]) s = true;
                if (big[i] >= big[i-1]) b = true;
            }
            okSmall[i] = s;
            okBig[i] = b;
        }

        // suffix DP: sufSmall[i] = possible to arrange cols [i..N-1] so that bottom at i = small[i]
        // sufBig[i] = possible ... bottom at i = big[i]
        vector<char> sufSmall(N, 0), sufBig(N, 0);
        sufSmall[N-1] = 1; sufBig[N-1] = 1;
        for (int i = N-2; i >= 0; --i) {
            bool s = false, b = false;
            if (sufSmall[i+1]) {
                if (small[i] <= small[i+1]) s = true;
                if (big[i] <= small[i+1]) b = true;
            }
            if (sufBig[i+1]) {
                if (small[i] <= big[i+1]) s = true;
                if (big[i] <= big[i+1]) b = true;
            }
            sufSmall[i] = s;
            sufBig[i] = b;
        }

        bool ok = false;
        for (int j = 0; j < N; ++j) {
            // try top at j = small[j]
            if (okSmall[j]) {
                // bottom at j can be small[j] (sufSmall) or big[j] (sufBig)
                if (sufSmall[j]) { ok = true; break; }
                if (sufBig[j]) { ok = true; break; } // small[j] <= big[j] always
            }
            // try top at j = big[j]
            if (okBig[j]) {
                if (sufBig[j]) { ok = true; break; } // big[j] <= big[j]
                if (sufSmall[j] && big[j] <= small[j]) { ok = true; break; }
            }
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}