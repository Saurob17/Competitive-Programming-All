#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int> b = a;
        sort(b.begin() + 1, b.end());   // target sorted array

        vector<bool> vis(n + 1, false);
        bool ok = true;

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {

                vector<int> idx, val;
                int x = i;

                // build one chain: i → 2i → 4i ...
                while (x <= n) {
                    vis[x] = true;
                    idx.push_back(x);
                    val.push_back(a[x]);
                    x *= 2;
                }

                sort(val.begin(), val.end());

                for (int j = 0; j < idx.size(); j++) {
                    if (val[j] != b[idx[j]]) {
                        ok = false;
                        break;
                    }
                }

                if (!ok) break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}
