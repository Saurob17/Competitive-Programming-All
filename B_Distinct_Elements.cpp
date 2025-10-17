#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> b(n + 1, 0); 
        for (int i = 1; i <= n; ++i) cin >> b[i];

        vector<long long> d(n + 1, 0), p(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            d[i] = b[i] - b[i - 1];
            p[i] = i - d[i]; 
            
        }

        vector<int> nxt(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            if (p[i] > 0) {
                int j = (int)p[i];
                nxt[j] = i;
            }
        }
        vector<int> a(n + 1, 0);
        int label = 1;
       
        for (int i = 1; i <= n; ++i) {
            if (p[i] == 0) {
                int cur = i;
                while (cur != 0) {
                    a[cur] = label;
                    cur = nxt[cur];
                }
                ++label;
            }
        }
     
        for (int i = 1; i <= n; ++i) {
            if (i > 1) cout << ' ';
            cout << a[i];
        }
        cout <<endl;
    }
 
}