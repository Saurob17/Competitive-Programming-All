// array roted
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;

        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        k = k % n;
        for (int i = n - k; i < n; i++)
        {
            cout << v[i] << " ";
        }
        for (int i = 0; i < n - k; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}