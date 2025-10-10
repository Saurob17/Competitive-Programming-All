#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int sum = 0;
        int mid = (n + 1) / 2;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back({x, i + 1});
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b)
             { return a.first > b.first; });
        vector<int> ans(n + 1);
        ans[0] = 0;
        int up = 1, dn = -1;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                ans[v[i].second] = up;
               
                 sum += 2 * v[i].first * up;
             up += 1;
            }
            else
            {
                ans[v[i].second] = dn;
                 sum += 2 * v[i].first * abs(dn);
                dn -= 1;
            }
        }
        int val = 0;

            cout << sum << endl;
            for (int j = 0; j <= n; j++)
            {
                cout << ans[j] << " ";
            }
            cout << endl;
        
        cout << endl;
    }
    return 0;
}
