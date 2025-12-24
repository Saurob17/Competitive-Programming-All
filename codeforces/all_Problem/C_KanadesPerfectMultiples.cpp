#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        /* code */

        int k, n;
        cin >> n >> k;

        unordered_map<int, int> mp;
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            st.insert(x);
        }
        unordered_map<int, int> m;

        for (auto it : st)
        {
            m[it] = 1;
        }

        int f = 0;
        vector<int> v;
        for (auto it : st)
        {
            if (mp[it] == 0)
            {
                for (int i = it; i <= k; i += it)
                {
                    if (m[i] != 1)
                    {
                          f = 1;
                        break;
                    }
                   
                    mp[i] = 1;
                }
                v.push_back(it);
            }
            if (f)
                break;
        }
        if(f){
            cout<<-1<<endl;
        }
        else{
            cout<<v.size()<<endl;
            for(auto it:v){
                cout<<it<<" ";
            }
            cout<<endl;
        }

    }
}