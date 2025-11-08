#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; if (!(cin >> N)) return 0;
    vector<int> W(N);
    vector<long long> H(N), B(N);
    long long sumB = 0;
    int totalW = 0;
    for (int i = 0; i < N; ++i) {
        cin >> W[i] >> H[i] >> B[i];
        sumB += B[i];
        totalW += W[i];
    }

    int cap = totalW / 2; // head weight must be <= body weight

    vector<long long> dp(cap + 1, 0);
    for (int i = 0; i < N; ++i) {
        
        long long val = H[i] - B[i];
        if (val <= 0) continue; // never beneficial to put on head
        int w = W[i];
        for (int c = cap; c >= w; --c) {
            dp[c] = max(dp[c], dp[c - w] + val);
        }
    }
    long long bestExtra = *max_element(dp.begin(), dp.end());
    cout << (sumB + bestExtra) << '\n';
    return 0;
}