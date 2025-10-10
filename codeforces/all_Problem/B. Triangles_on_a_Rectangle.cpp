#include <bits/stdc++.h>
using namespace std;

#define int long long   // ✅ এখানে define করা হলো int = long long

int32_t main()          // ✅ main ফাংশনকে int32_t রাখা হলো (সাধারণত long long define করলে এমন করা হয়)
{
    int t;
    cin >> t;
    while (t--)
    {
        int w, h;
        cin >> w >> h;
      
        int ans = LLONG_MIN;
        for (int i = 1; i <= 4; i++)
        {
            int fst;
            cin >> fst;

            int first = LLONG_MAX, second = LLONG_MIN;
            for (int j = 0; j < fst; j++)
            {
                int x;
                cin >> x;
                first = min(first, x);
                second = max(second, x);
            }

            if (i <= 2)
                ans = max(ans, (second - first) * h);
            else
                ans = max(ans, (second - first) * w);
        }
        cout << ans << endl;
    }
    return 0;
}
