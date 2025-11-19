#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        long long sumW = 0, maxW = 0;
        for (int i = 0; i < n; ++i)
        {
            long long w = max(a[i], a[(i + 1) % n]);
            sumW += w;
            if (w > maxW)
                maxW = w;
        }
        cout << (sumW - maxW) << '\n';
    }
    return 0;
}