#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{

    int n;
    cin >> n;

    string s;
    cin >> s;

    int c = 0, f = 0;
    int l = 0, r = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] > s[i + 1] && f == 0)
        {
            c++;
            l = i;
            r = i + 1;
            f = 1;
        }
        if (f == 1 && s[i] > s[i + 1])
        {
            r = i + 1;
        }
        else if (f == 1)
        {
            break;
        }
    }

    if (c == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << l + 1 << " " << r + 1 << endl;
    }
}
