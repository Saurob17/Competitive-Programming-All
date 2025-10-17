#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1'000'005;

int parent[MAXN]; 
int cnt[MAXN];     

int find_next(int x) {
    if (x > MAXN) return MAXN;
    if (parent[x] == x) return x;
    return parent[x] = find_next(parent[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    
    for (int i = 1; i <= N + 1; i++) {
        parent[i] = i;
        cnt[i] = (i <= N);
    }

    while (Q--) {
        int X, Y;
        cin >> X >> Y;

        int upgraded = 0;

       
        for (int v = find_next(1); v <= X; v = find_next(v)) {
            upgraded += cnt[v];
            cnt[Y] += cnt[v];  
            cnt[v] = 0;
            parent[v] = find_next(v + 1); 
        }

        cout << upgraded << "\n";
    }

    return 0;
}
