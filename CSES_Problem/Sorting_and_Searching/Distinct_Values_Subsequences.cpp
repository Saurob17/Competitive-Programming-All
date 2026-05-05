#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    map<int,int> freq;

    for (int x : a) {
        freq[x]++;
    }

    long long ans = 1;

    for (auto [val, f] : freq) {
        ans = (ans * (f + 1)) % MOD;
    }

    ans = (ans - 1 + MOD) % MOD;

    cout << ans << endl;
}