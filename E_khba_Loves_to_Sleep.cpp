#include <bits/stdc++.h>
using namespace std;

struct Range
{
    long long l, r;
    int dir;
}; // dir = -1 pick r--, dir = 1 pick l++
struct Cmp
{
    bool operator()(const Range &a, const Range &b) const
    {
        return (a.r - a.l) < (b.r - b.l); // max-heap by length
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        long long n, k, x;
        cin >> n >> k >> x;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());

        priority_queue<Range, vector<Range>, Cmp> pq;
        // Left boundary free segment [0, a[0]-1]
        if (a[0] > 0)
            pq.push(Range{0, a[0] - 1, 1});
        // Right boundary free segment [a[n-1]+1, x]
        if (a.back() < x)
            pq.push(Range{a.back() + 1, x, -1});
        // Internal gaps between friends
        for (int i = 1; i < n; i++)
        {
            long long l = a[i - 1] + 1;
            long long r = a[i] - 1;
            if (l > r)
                continue;
            long long mid = (l + r) >> 1;
            // Left half [l, mid] picks from right endpoint moving left
            if (l <= mid)
                pq.push(Range{l, mid, -1});
            // Right half [mid+1, r] picks from left endpoint moving right
            if (mid + 1 <= r)
                pq.push(Range{mid + 1, r, 1});
        }

        vector<long long> ans;
        ans.reserve(k);
        unordered_set<long long> used;
        while ((long long)ans.size() < k && !pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            if (cur.l > cur.r)
                continue;
            long long pick = (cur.dir == -1 ? cur.r : cur.l);
            if (used.count(pick))
            {
                // skip this endpoint but keep the range for future
                pq.push(cur);
                continue;
            }
            ans.push_back(pick);
            used.insert(pick);
            if ((long long)ans.size() == k)
                break;
            if (cur.dir == -1)
            {
                cur.r--;
                if (cur.l <= cur.r)
                    pq.push(cur);
            }
            else
            {
                cur.l++;
                if (cur.l <= cur.r)
                    pq.push(cur);
            }
        }
        // Fallback: fill remaining from [0,x] if needed
        for (long long pos = 0; (long long)ans.size() < k && pos <= x; ++pos)
        {
            if (!used.count(pos))
            {
                ans.push_back(pos);
                used.insert(pos);
            }
        }
        sort(ans.begin(), ans.end());
        for (size_t i = 0; i < ans.size(); ++i)
        {
            cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
        }
    }
    return 0;
}