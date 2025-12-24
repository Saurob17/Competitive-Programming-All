#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int MAXA = 1e6;
    vector<int> freq(MAXA + 1, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    // Try all possible GCD values from large to small
    for (int g = MAXA; g >= 1; g--) {
        int cnt = 0;
        // Count how many numbers are divisible by g
        for (int multiple = g; multiple <= MAXA; multiple += g) {
            cnt += freq[multiple];
            if (cnt >= 2) {
                cout << g << '\n';
                return 0;
            }
        }
    }

    return 0;
}
