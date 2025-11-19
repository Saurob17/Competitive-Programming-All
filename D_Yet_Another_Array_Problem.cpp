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
        vector<long long> v(n);

        bool flag = false;

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        long long ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 2; j <= 100; j++)
            {

                if (std::gcd(v[i], j) == 1)
                {

                    ans = j;
                    flag = true;
                    break;
                }

            }
            if (flag == true)
            {
              
                break;
            }
        }

        if (flag)
        {
            cout << ans << endl;
        }
        else 
        {
            cout << -1 << endl;
        }
    }
}