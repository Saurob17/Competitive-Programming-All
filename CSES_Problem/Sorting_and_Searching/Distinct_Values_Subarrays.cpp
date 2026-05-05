#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
    }
    set<int> st;
   long long ans = 0;

    int l = 0, r = 0;
    while (r<n && l<=r)
    {

        int val = v[r];

        while ((st.count(val)))
            
        {
            st.erase(v[l]);
            l++;
        }
        st.insert(val);
        ans += (r - l + 1);
        r++;
    }

    cout << ans;
}