#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<int, int> fn(vector<int> a)
{
    unordered_map<int, int> m;

    for (int x : a)
        m[x]++;

    vector<int> v;

    for (auto &p : m)
        if (p.second % 2 == 1)
            v.push_back(p.first);

    if (v.empty())
        return {0, 0};

    sort(v.rbegin(), v.rend());

    int x = v[0];
    int y = (v.size() > 1 ? v[1] : 0);

    return {x, y};
}

int32_t main()
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

        sort(a.rbegin(), a.rend());

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[a[i]]++;

        int even = 0;
        int sum = 0;
        int nite = 0;
        int w = 0, z = 0;
        int f = 0, od = 0;
        int mx = INT_MIN;

        for (auto x : mp)
        {
            if (f < 2 && x.second % 2 != 0)
            {
                if (f == 0)
                    w = x.first;
                else
                    z = x.first;
                f++;
            }

            if (x.second % 2 == 0)
            {
                sum += (x.first * x.second);
                even++;
            }
            else
            {
                sum += (x.second - 1) * x.first;
                mx = max(mx, x.first);
                od = 1; 
            }
        }

        pair<int, int> maxTwo = fn(a);
        w = maxTwo.first;
        z = maxTwo.second;

        int tree = sum + min(w, z);

        if (even == 0)
        {
            cout << 0 << endl;
        }
        else if (n == 3 && od == 1 && sum <= mx)
        {
            cout << 0 << endl;
        }
        else if (mx >= sum)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << sum + w + z << endl;
        }
    }
}
