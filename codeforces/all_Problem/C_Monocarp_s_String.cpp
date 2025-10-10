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
        string s;
        int a = 0, b = 0, a1 = 0, b1 = 0;
        cin >> s;
        int l = 0, l2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                a++;
            else
                b++;
            if (a == b)
            {
                l = i + 1;
            }
        }
        int p = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            p++;
            if (s[i] == '0')
                a1++;
            else
                b1++;
            if (a1 == b1)
            {
                l2 = p;
            }
        }
        if (l == n || l2 == n)
        {
            cout<< -1 << endl;
        }
        else{
             cout << min((n - l), (n - l2)) << endl;
        }
       
    }
}