#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

struct Node {
    long long val;
    int prev, next;
    bool alive;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int q; cin >> q;
        vector<int> queries(q);
        int maxX = 0;
        for (int i = 0; i < q; ++i) { cin >> queries[i]; maxX = max(maxX, queries[i]); }

        vector<long long> scores(maxX + 1, 0);

        // build initial nodes
        vector<Node> nodes;
        nodes.reserve(n + maxX + 5);
        for (int i = 0; i < n; ++i) {
            Node nd;
            nd.val = a[i];
            nd.prev = (i == 0 ? -1 : i - 1);
            nd.next = (i == n - 1 ? -1 : i + 1);
            nd.alive = true;
            nodes.push_back(nd);
        }

        // max-heap of (sum, left_idx, right_idx)
        using T = tuple<long long,int,int>;
        auto cmp = [](const T &x, const T &y) { return get<0>(x) < get<0>(y); };
        priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);
        for (int i = 0; i + 1 < n; ++i) pq.emplace(nodes[i].val + nodes[i+1].val, i, i+1);

        for (int op = 1; op <= maxX; ++op) {
            // find valid pair
            while (!pq.empty()) {
                auto [s, l, r] = pq.top();
                if (l >= (int)nodes.size() || r >= (int)nodes.size()) { pq.pop(); continue; }
                if (!nodes[l].alive || !nodes[r].alive) { pq.pop(); continue; }
                if (nodes[l].next != r || nodes[r].prev != l) { pq.pop(); continue; }
                // valid
                pq.pop();
                // update score
                long long add = s % MOD;
                if (add < 0) add += MOD;
                scores[op] = (scores[op-1] + add) % MOD;

                // create new node with value s
                int idx = nodes.size();
                Node nd;
                nd.val = s;
                nd.prev = l;
                nd.next = r;
                nd.alive = true;
                nodes.push_back(nd);

                // relink
                nodes[l].next = idx;
                nodes[r].prev = idx;

                // push new adjacent pairs
                pq.emplace(nodes[l].val + nodes[idx].val, l, idx);
                pq.emplace(nodes[idx].val + nodes[r].val, idx, r);

                break;
            }
            if (pq.empty()) {
                // no more pairs
                for (int k = op; k <= maxX; ++k) scores[k] = scores[k-1];
                break;
            }
        }

        for (int i = 0; i < q; ++i) {
            if (i) cout << ' ';
            cout << scores[queries[i]];
        }
        cout << '\n';
    }
    return 0;
}
