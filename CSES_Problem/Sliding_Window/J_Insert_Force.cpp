#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128_t;
static const i64 MOD = 998244353LL;

// fibonacci modulo cache
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
    return (l1.b - l2.b) / (l2.m - l1.m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute exact small Fibonacci for r progression and exact A/B
    const int LIM128 = 200; // extended for safety in exact comparisons
    vector<i128> fib128(LIM128 + 5);
    fib128[0] = 0; fib128[1] = 1;
    for (int i = 2; i <= LIM128; ++i) fib128[i] = fib128[i - 1] + fib128[i - 2];

    const int EXACT_LIMIT = 90; // exact handling for x <= 90

    int t; if (!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<i64> a(n);
        i64 maxA = 0;
        for (int i = 0; i < n; ++i) { cin >> a[i]; if (a[i] > maxA) maxA = a[i]; }
        int q; cin >> q;
        vector<int> qs(q);
        int maxX = 0;
        for (int i = 0; i < q; ++i) { cin >> qs[i]; maxX = max(maxX, qs[i]); }

        ensureFibMod(maxX + 3);

        if (n < 2) {
            for (int i = 0; i < q; ++i) cout << 0 << (i+1==q? '\n' : ' ');
            continue;
        }

        // Precompute exact best indices for small x
        int up = min(EXACT_LIMIT, maxX);
        vector<int> bestExact(up + 1, 0);
        if (n >= 2) {
            for (int x = 1; x <= up; ++x) {
                i128 A = fib128[x + 2] - 1;
                i128 B = fib128[x + 3] - 2;
                i128 bestVal = numeric_limits<long long>::min();
                int bestI = 0;
                for (int i = 0; i + 1 < n; ++i) {
                    i128 u = (i128)a[i];
                    i128 v = (i128)a[i + 1];
                    i128 val = A * u + B * v;
                    if (val > bestVal) { bestVal = val; bestI = i; }
                }
                bestExact[x] = bestI;
            }
        }

        // compress by slope v = a[i+1], keep max intercept u = a[i]
        int MAXA = (int)maxA;
        vector<i64> bestU(MAXA + 1, -1);
        for (int i = 0; i + 1 < n; ++i) {
            int v = (int)a[i+1];
            i64 u = a[i];
            if (bestU[v] < u) bestU[v] = u;
        }

        vector<Line> lines;
        lines.reserve(n);
        for (int v = 0; v <= MAXA; ++v) if (bestU[v] >= 0) {
            Line L; L.mi = v; L.bi = bestU[v]; L.m = (long double)v; L.b = (long double)bestU[v];
            lines.push_back(L);
        }
        sort(lines.begin(), lines.end(), [](const Line &x, const Line &y){
            if (x.mi != y.mi) return x.mi < y.mi;
            return x.bi > y.bi;
        });

        // Build upper envelope
        vector<Line> hull;
        vector<long double> xleft; // x where this line becomes better than previous
        const long double NEG_INF = -numeric_limits<long double>::infinity();
        const long double EPS = 1e-18L;
        for (auto &ln : lines) {
            if (hull.empty()) {
                hull.push_back(ln);
                xleft.push_back(NEG_INF);
            } else {
                while (hull.size() >= 2) {
                    long double x1 = intersectX(hull[hull.size()-2], hull.back());
                    long double x2 = intersectX(hull.back(), ln);
                    if (x2 <= x1 + EPS) { hull.pop_back(); xleft.pop_back(); }
                    else break;
                }
                long double cross = intersectX(hull.back(), ln);
                hull.push_back(ln);
                xleft.push_back(cross);
            }
        }

        // Precompute r(x) for all x up to maxX using long double recurrence with renormalization
        vector<long double> rvals(maxX + 1);
        if (maxX >= 1) {
            long double D = 1.0L; // F3-1
            long double N = 1.0L; // F4-2
            long double Fk1 = 1.0L; // F2
            long double Fk2 = 2.0L; // F3
            rvals[1] = N / D;
            for (int x = 2; x <= maxX; ++x) {
                D += Fk1;
                N += Fk2;
                long double Fnext = Fk1 + Fk2;
                Fk1 = Fk2;
                Fk2 = Fnext;
                const long double TH = 1e200L, SF = 1e100L;
                if (fabsl(D) > TH || fabsl(N) > TH || fabsl(Fk1) > TH || fabsl(Fk2) > TH) {
                    D /= SF; N /= SF; Fk1 /= SF; Fk2 /= SF;
                }
                rvals[x] = N / D;
            }
        }

        // Answer queries: for x<=up use bestExact; else use hull and rvals[x]
        for (int i = 0; i < q; ++i) {
            int x = qs[i];
            if (x <= up) {
                int idx = bestExact[x];
                i64 u = a[idx] % MOD; if (u < 0) u += MOD;
                i64 v = a[idx + 1] % MOD; if (v < 0) v += MOD;
                i64 Amod = (fibMod[x + 2] - 1) % MOD; if (Amod < 0) Amod += MOD;
                i64 Bmod = (fibMod[x + 3] - 2) % MOD; if (Bmod < 0) Bmod += MOD;
                i64 val = ( ( (__int128)Amod * u ) % MOD + ( (__int128)Bmod * v ) % MOD ) % MOD;
                cout << val;
            } else {
                long double r = rvals[x];
                // binary search hull by xleft
                int lo = 0, hi = (int)hull.size() - 1;
                int pos = 0;
                while (lo <= hi) {
                    int mid = (lo + hi) >> 1;
                    if (xleft[mid] <= r) { pos = mid; lo = mid + 1; }
                    else hi = mid - 1;
                }
                const Line &best = hull[pos];
                i64 u = best.bi % MOD; if (u < 0) u += MOD;
                i64 v = best.mi % MOD; if (v < 0) v += MOD;
                i64 Amod = (fibMod[x + 2] - 1) % MOD; if (Amod < 0) Amod += MOD;
                i64 Bmod = (fibMod[x + 3] - 2) % MOD; if (Bmod < 0) Bmod += MOD;
                i64 val = ( ( (__int128)Amod * u ) % MOD + ( (__int128)Bmod * v ) % MOD ) % MOD;
                cout << val;
            }
            cout << (i+1==q? '\n' : ' ');
        }
    }
    return 0;
}