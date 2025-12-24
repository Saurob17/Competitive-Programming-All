#include <bits/stdc++.h>
using namespace std;
int main()
{
  
        /* code */
        int n;
        cin >> n;
        vector<int> v(n), vc;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int mx = *max_element(v.begin(), v.end());
        long long to = 0;
        for (auto it : v)
        {
            to += (mx - it);
            if (mx - it > 0)
            {
                int dif = mx - it;
                vc.push_back(dif);
            }
        }
        if (vc.size() == 0)
        {
            cout << 0 << " "<<0<<endl;
        }
        else
        {
            long long g = vc[0];
            for (auto it : vc)
            {
                g = gcd(it, g);
            }
            cout<<to/g<<" "<<g<<endl;
        }
    }
