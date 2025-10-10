#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    vector<int> v(3 * 1e5 + 1);
    v[0] = 0;
    for (int i = 1; i <= 3 * 1e5; i++)
    {
        v[i] = v[i - 1] ^ i;
    }
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = v[a-1];

        if (ans == b)
        {
            cout << a << endl;
        }
        else if ((ans ^ b) != a)
        {
            cout << a + 1 << endl;
        }
        else
        {
            cout << a + 2 << endl;
        }
    }
}