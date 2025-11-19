#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool odd = false, even = false;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
            if (x % 2 == 0)
                even = true;
            else
                odd = true;
        }
        if (odd && even)
        {
            sort(v.begin(), v.end());
            for (auto &it : v)
                cout << it << " ";
            cout << endl;
        }
        else
        {
            for (auto &it : v)
                cout << it << " ";
            cout << endl;
        }
    }
}