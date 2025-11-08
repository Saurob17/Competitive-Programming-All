#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, n;
    cin >> x >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    map<int, int> m;
    int q;
    cin >> q;
    while (q--)
    {
        int p;
        cin >> p;
        if (m[p] == 0)
        {
            x += v[p - 1];
            m[p]++;
            cout << x << endl;
        }
        else
        {
            x -= v[p - 1];
            m[p]--;
            cout << x << endl;
        }
    }
}