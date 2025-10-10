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

        vector<int> a(n);
        map<int, int> m;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
            if (m[a[i]] > 1)
            {
                flag = 1;
            }
        }
       
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}