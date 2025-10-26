#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n + 1), pm(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 1; i <= n; ++i)
            pm[i] = max(pm[i - 1], a[i]);

        long long ans = 0;
        for (int i = 1; i <= n; i += 2)
        {
            long long li = LLONG_MAX;
            if (i > 1)
                li = min(li, pm[i - 1] - 1);
            if (i < n)
                li = min(li, pm[i + 1] - 1);
            if (li == LLONG_MAX)
                continue;
            if (a[i] > li)
                ans += a[i] - li;
        }
        cout << ans << '\n';
    }
    
}
