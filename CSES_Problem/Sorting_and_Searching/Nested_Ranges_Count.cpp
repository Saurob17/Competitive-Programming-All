#include <bits/stdc++.h>
using namespace std;

#define int long long

struct FenwickTree {
    int n;
    vector<int> bit;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 5, 0);
    }

    void update(int i, int val) {
        for (; i <= n; i += i & -i)
            bit[i] += val;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }
};

struct Range {
    int x, y, idx;
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Range> a(n);
    vector<int> ys;

    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].idx = i;
        ys.push_back(a[i].y);
    }

    // coordinate compression
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    auto getY = [&](int y) {
        return lower_bound(ys.begin(), ys.end(), y) - ys.begin() + 1;
    };

    for (auto &r : a) {
        r.y = getY(r.y);
    }

    // sort by x asc, y desc
    sort(a.begin(), a.end(), [](Range &p, Range &q) {
        if (p.x == q.x) return p.y > q.y;
        return p.x < q.x;
    });

    vector<int> contains(n), contained_by(n);

    FenwickTree bit(ys.size() + 2);

    // -------------------------
    // 1. contains (how many it contains)
    // -------------------------
    for (int i = n - 1; i >= 0; i--) {
        contains[a[i].idx] = bit.query(a[i].y);
        bit.update(a[i].y, 1);
    }

    // reset BIT
    bit = FenwickTree(ys.size() + 2);

    // -------------------------
    // 2. contained_by (how many contain it)
    // -------------------------
    for (int i = 0; i < n; i++) {
        contained_by[a[i].idx] = bit.query(ys.size()) - bit.query(a[i].y - 1);
        bit.update(a[i].y, 1);
    }

    // output
    for (int i = 0; i < n; i++) cout << contains[i] << " ";
    cout << "\n";

    for (int i = 0; i < n; i++) cout << contained_by[i] << " ";
    cout << "\n";

    return 0;
}