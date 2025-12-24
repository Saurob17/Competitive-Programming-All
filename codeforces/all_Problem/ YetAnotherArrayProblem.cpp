#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        vector<long long> v(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        long long ans = LLONG_MAX;

        for (long long i = 0; i < n; i++)
        {
            for (long long j = 2; j <= 100; j++)
            {
                if (gcd(j, v[i]) == 1)
                {
                    ans = min(ans, j);
                    break;
                }
            }
        }

        if (ans == LLONG_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}
