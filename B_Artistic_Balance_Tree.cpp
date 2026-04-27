#include <bits/stdc++.h>
using namespace std;
int main()
{
   
    int t;
    cin >> t;
    while (t--)
    {
        int od = 0, ev = 0;
        int n, m;
        cin >> n >> m;
        vector<long long> odd, eve;
        long long x;
        long long tot = 0;
      
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            tot += x;
            if (i & 1)
            {
                odd.push_back(x);
            }
            else
            {
                eve.push_back(x);
            }
        }
        for (int i = 1; i <= m; i++)
        {
            int y;
            cin >> y;
            if (y & 1)
            {
                od++;
            }
            else
                ev++;
        }
        
        sort(odd.rbegin(), odd.rend());
        sort(eve.rbegin(), eve.rend());
        long long mrks = 0;
        
        if (od > 0 && !odd.empty()) {
            mrks += odd[0];
            int odl=odd.size();
            for (int i = 1; i < min(od,odl); i++) {  
                if(odd[i] > 0) {
                    mrks += odd[i];
                }
            }
        }
        
        if (ev > 0 && !eve.empty()) {
            mrks += eve[0];
            int evln=eve.size();
            for (int i = 1; i < min(ev, evln); i++) {  
                if(eve[i] > 0) {
                    mrks += eve[i];
                }
            }
        }
       
        cout << tot - mrks <<endl;
    }
   
}