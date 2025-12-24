#include <bits/stdc++.h>
using namespace std;
int32_t main()
{

        ios_base::sync_with_stdio(false); // Fast I/O
    cin.tie(NULL);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        map<long, long> m;
        cin >> n;
        vector<long long> v(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> v[i];
            m[v[i]]++;
        }
        long long mx = *max_element(v.begin(), v.end());
        long long g = 0;
        long long to = 0;
        for (auto it : v)
        {
            to += (mx - it);
            g = gcd(g, mx - it);
        }
        long long st = mx;
        long long tim =  1e5*2;
        while (tim--)
        {
            if (!m[st])
            {
                
                break;
            }
            st-=g;
        }

        if (g == 0)
            cout << 1 << endl;
        else
        {
            cout << (to + (mx - st)) / g << endl;
        }
        // cout<<"g "<<st<<endl;
    }
}