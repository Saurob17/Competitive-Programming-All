#include <bits/stdc++.h>
using namespace std;
int main()
{
   // cout << gcd(4, 30) << endl;
    int t;
    cin >> t;
    while (t--)
    {
        long long a;
        cin >> a;
        vector<int> v(a);
        cin >> v[0];
        int ans = v[0];
        for (int i = 1; i < a; i++)
        {
            cin >> v[i];
            ans = gcd(ans, v[i]);
        }
        if (ans == 1)
        {
            cout << 0 << endl;
            continue;
        }
        int pri=ans;
        int costt = INT_MAX;
    
        for (int i = a; i >= 1; i--)
        {    int cost = 0;
            ans=pri;
            for (int j = i; j >= 1; j--)
            {
                cost += (a - j+1);
                ans = gcd(ans, j);
                if (ans == 1)
               // cout<<i<<" "<<j<<endl;
                    break;
            }

            costt = min(costt, cost);
        }
        cout<<costt<<endl;
    }
}