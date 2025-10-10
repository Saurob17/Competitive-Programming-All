#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int min_neg = INT_MAX;
        int _count = 0;
        bool flag = false;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                if (x == 0)
                {
                    flag = true;
                }
                sum += abs(x);

                if (x < 0)
                {

                    _count++;
                }
                if (x != 0)
                {
                    min_neg = min(min_neg, abs(x));
                }
                
            }

        }

        if (flag)
        {
            cout << sum << endl;
        }
        else
        {
            if (_count % 2 == 0)
            {
                cout << sum << endl;
            }
            else
            {
                cout << sum - 2 * min_neg << endl;
            }
        }
    }
}