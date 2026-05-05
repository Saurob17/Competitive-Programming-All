#include <bits/stdc++.h>
using namespace std;

struct Range {
    int l, r, id;
};

// Crucial: Sort L ascending, and R DESCENDING for same L
bool cmp(const Range &a, const Range &b) {
    if (a.l == b.l) return a.r > b.r;
    return a.l < b.l;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<Range> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].l >> v[i].r;
        v[i].id = i;
    }

    sort(v.begin(), v.end(), cmp);

    vector<int> contains(n, 0), is_contained(n, 0);

    // Is contained? (Check max end-point from the left)
    int max_r = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].r <= max_r) is_contained[v[i].id] = 1;
        max_r = max(max_r, v[i].r);
    }

    // Contains others? (Check min end-point from the right)
    int min_r = 2e9;
    for (int i = n - 1; i >= 0; i--) {
        if (v[i].r >= min_r) contains[v[i].id] = 1;
        min_r = min(min_r, v[i].r);
    }

    for (int i = 0; i < n; i++) cout << contains[i] << (i == n - 1 ? "" : " ");
    cout << endl;
    for (int i = 0; i < n; i++) cout << is_contained[i] << (i == n - 1 ? "" : " ");
    cout << endl;
}