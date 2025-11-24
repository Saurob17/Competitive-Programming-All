#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128_t;

static const i64 MOD = 998244353LL;

// Fibonacci modulo cache
static vector<i64> fibMod = {0, 1};

void ensureFibMod(int need) {
    if ((int)fibMod.size() > need) return;
    fibMod.reserve(need + 1);
    while ((int)fibMod.size() <= need) {
        size_t m = fibMod.size();
        fibMod.push_back((fibMod[m - 1] + fibMod[m - 2]) % MOD);
    }
}

struct Line {
    long double m; // slope = v
    long double b; // intercept = u
    i64 mi; // integer slope
    i64 bi; // integer intercept
};

static inline long double intersectX(const Line& l1, const Line& l2) {
    // Assumes l1.m != l2.m
    return (l1.b - l2.b) / (l2.m - l1.m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; if (!(cin >> t)) return 0;
    const long double EPS = 1e-18L;
    const long double NEG_INF = -numeric_limits<long double>::infinity();
    const long double PHI = (sqrtl(5.0L) + 1.0L) / 2.0L;

    while (t--) {
        int n; cin >> n;
        vector<i64> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int q; cin >> q;
        vector<int> xs(q);
        int maxX = 0;
        for (int i = 0; i < q; ++i) { cin >> xs[i]; maxX = max(maxX, xs[i]); }

        ensureFibMod(maxX + 3);

        if (n < 2) {
            for (int i = 0; i < q; ++i) cout << 0 << (i + 1 == q ? '\n' : ' ');
            continue;
        }

        // Compress lines by slope v = a[i+1]: keep maximum intercept u = a[i]
        int maxA = 200000; // as per constraints
        vector<i64> bestU(maxA + 1, -1);
        for (int i = 0; i + 1 < n; ++i) {
            int v = (int)a[i + 1];
            i64 u = a[i];
            if (bestU[v] < u) bestU[v] = u;
        }

        vector<Line> lines;
        lines.reserve(n);
        for (int v = 0; v <= maxA; ++v) if (bestU[v] >= 0) {
            Line L; L.mi = v; L.bi = bestU[v]; L.m = (long double)v; L.b = (long double)bestU[v];
            lines.push_back(L);
        }

        // Sort by slope ascending
        sort(lines.begin(), lines.end(), [](const Line& x, const Line& y){
            if (x.mi != y.mi) return x.mi < y.mi;
            return x.bi > y.bi; // higher intercept first (though unique due to compress)
        });

        // Build upper envelope (Convex Hull Trick) for maximizing u + r*v for increasing r
        vector<Line> hull;
        vector<long double> xleft; // x-coordinate where this line becomes better than previous
        for (const auto& ln : lines) {
            // Since slopes unique after compression, no need to handle equal slopes here
            while (hull.size() >= 2) {
                long double x1 = intersectX(hull[hull.size()-2], hull.back());
                long double x2 = intersectX(hull.back(), ln);
                if (x2 <= x1 + EPS) {
                    hull.pop_back();
                    xleft.pop_back();
                } else break;
            }
            if (hull.empty()) {
                hull.push_back(ln);
                xleft.push_back(NEG_INF);
            } else {
                long double cross = intersectX(hull.back(), ln);
                hull.push_back(ln);
                xleft.push_back(cross);
            }
        }

        // Precompute exact r for x<=60
        const int LIMR = 60;
        vector<long double> rExact(LIMR + 1, 0.0L);
        {
            vector<unsigned long long> F(65); F[0] = 0; F[1] = 1; for (int i = 2; i <= 64; ++i) F[i] = F[i-1] + F[i-2];
            for (int x = 1; x <= LIMR; ++x) {
                unsigned long long Num = F[x+3] - 2ULL;
                unsigned long long Den = F[x+2] - 1ULL;
                rExact[x] = (long double)Num / (long double)Den;
            }
        }

        // Sort queries by r (x increasing sufficient because r non-decreasing and flat after LIMR)
        vector<int> ord(q); iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j){ return xs[i] < xs[j]; });

        // Process queries
        vector<i64> ans(q, 0);
        size_t ptr = 0; // pointer on hull
        for (int id : ord) {
            int x = xs[id];
            long double r = (x <= LIMR ? rExact[x] : PHI);
            while (ptr + 1 < hull.size() && r >= xleft[ptr + 1] - EPS) ++ptr;
            const Line& best = hull[ptr];
            i64 A = (fibMod[x + 2] - 1) % MOD; if (A < 0) A += MOD;
            i64 B = (fibMod[x + 3] - 2) % MOD; if (B < 0) B += MOD;
            i64 val = ( (i128)A * (best.bi % MOD) + (i128)B * (best.mi % MOD) ) % MOD;
            ans[id] = val;
        }

        for (int i = 0; i < q; ++i) cout << ans[i] << (i + 1 == q ? '\n' : ' ');
    }

    return 0;
}
;