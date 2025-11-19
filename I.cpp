#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int ca = 1;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        vector<int> preMax(n), sufMin(n);
        preMax[0] = INT_MIN; 
        for (int i = 1; i < n; ++i) preMax[i] = max(preMax[i-1], a[i-1]);
        sufMin[n-1] = INT_MAX; 
        for (int i = n-2; i >= 0; --i) sufMin[i] = min(sufMin[i+1], a[i+1]);

        int ans = -1;
        for (int i = 0; i < n; ++i) {
            if (a[i] > preMax[i] && a[i] < sufMin[i]) { ans = i + 1; break; }
        }
        cout << "Case " << ca++ << ": ";
        if (ans == -1) cout << "Humanity is doomed!\n"; else cout << ans << '\n';
    }
    return 0;
}
