#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;

    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    vector<long long> v(n);
    v[0] = x;

    for (int i = 1; i < n; i++) {
        v[i] = (v[i - 1] * a + b) % c;
    }


    deque<int> dq;
    vector<long long> ans;

    for (int i = 0; i < n; i++) {
        // window এর বাইরে গেলে pop
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        // বড় element বাদ দিতে হবে back থেকে
        while (!dq.empty() && v[i] <= v[dq.back()])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            ans.push_back(v[dq.front()]);
    }

    long long val = 0;
    for (int i = 0; i < ans.size(); i++)
        val ^= ans[i];

    cout << val << "\n";

    return 0;
}
