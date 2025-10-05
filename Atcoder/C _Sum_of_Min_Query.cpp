#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n), v1(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += min(v[i], v1[i]);
    }
    char c;
    int x, vi;

    while (q--)
    {
        cin >> c >> x >> vi;

        if (c == 'A')
        {
            int pri = min(v[x - 1], v1[x - 1]);
            v[x - 1] = vi;
            sum -= pri;
            int curr = min(v[x - 1], v1[x - 1]);
            sum += curr;

            cout<<sum<<endl;
        }
        else
        {
            int pri2 = min(v[x - 1], v1[x - 1]);
            v1[x - 1] = vi;
            sum -= pri2;
            int curr2 = min(v[x - 1], v1[x - 1]);
            sum += curr2;
            cout<<sum<<endl;
        }
    }
}