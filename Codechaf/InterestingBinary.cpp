#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int k;
        cin >> k;

        int cnt = 0;
        int r = 0;
        if (k >= 0)
        {
            r = sqrt(k);
        }
  
        if (k < 0)
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = -r; i <= r + 1; i++)
        {
            for (int j = -r; j <= r; j++)
            {
                if ((i * i) + (j * j) <= k)
                {
                    cnt++;
                }
            }
        }
        if (k >= 0)
        {
            cout << cnt << endl;
        }
       
    }
}