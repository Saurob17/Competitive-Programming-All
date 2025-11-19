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

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int c = 0;
        int fs = 0, sn = 0;
        bool ispossible = true;

        vector<int> leftmn(n), rightmx(n);
        leftmn[0] = a[0];

        for (int i = 1; i < n; i++)
        {
            leftmn[i] = min(leftmn[i - 1], a[i]);
        }
        rightmx[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightmx[i] = max(rightmx[i + 1], a[i]);
        }

        for (int i = 0; i < n; i++)
        {
            if (rightmx[i] >= (leftmn[i] * 2))
            {
                ispossible = false;
                break;
            }
        }
        if (ispossible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}