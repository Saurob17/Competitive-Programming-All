#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    vector<ll> pref(n);//oyuuuuuuuuuuuuuuuuuuuuuuutty
    pref[0] = a[0];//dsfjskdhfksjdfkjkjds
    for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + a[i];

    ll total = pref.back();

    while (q--) {
        ll b;
        cin >> b;

        ll val = b - 1;

        // lower_bound to find first index where A[i] >= b
        int idx = lower_bound(a.begin(), a.end(), b) - a.begin();

        ll leftSum = 0;
        if (idx > 0) leftSum = pref[idx - 1]; // যদি কোনো element < b থাকে

        ll rightCount = n - idx;

        ll S = leftSum + rightCount * val;
        ll ans = S + 1;

        if (ans > total) cout << -1 << '\n';
        else cout << ans << '\n';
    }

    return 0;
}
