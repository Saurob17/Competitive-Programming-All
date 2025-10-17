#include <bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int sum = 0;

        map<char, int> mp;
        int str = n;

        for (int i = 0; i < n; i++)
        {
            if (mp[s[i]] == 0)
            {
                sum += str;
            }
            mp[s[i]]++;
            str--;
        }
        cout << sum << endl;
    }

}