#include <bits/stdc++.h>
using namespace std;

pair<int,int> best_pair(int n){
    if(n == 0) return {0,0};
    if(__builtin_popcount((unsigned)n) == 1) return {0, n};
    int msb = 31 - __builtin_clz((unsigned)n);
    int M = 1 << msb;
    int r = n - M; // r > 0
    int h = 31 - __builtin_clz((unsigned)r);
    int z = (1 << h) - 1;
    int x = M + z;
    int y = r ^ z;
    return {x, y};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; if(!(cin >> t)) return 0;
    while(t--){
        int n, k; cin >> n >> k;
        if(k % 2 == 1){
            for(int i = 0; i < k; ++i){
                if(i) cout << ' ';
                cout << n;
            }
            cout << '\n';
            continue;
        }
        // k even
        for(int i = 0; i < k-2; ++i) cout << n << ' ';
        auto pr = best_pair(n);
        cout << pr.first << ' ' << pr.second << '\n';
    }
    return 0;
}
