#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int mn = v[i];
        int mx = v[i];
        unordered_set<int> s;
        s.insert(v[i]);
        for (int j = i + 1; j < n; j++)
        {
            if (s.find(v[j]) != s.end())
            {
                break;
            }
            s.insert(v[j]);

            mn = min(mn, v[j]);
            mx = max(mx, v[j]);
            
                int len = j - i + 1;
              
            if (mx - mn + 1 == len)
            {
                ans = max(ans, len);
            }
            
        }
    }
    cout<<ans<<endl;
}
