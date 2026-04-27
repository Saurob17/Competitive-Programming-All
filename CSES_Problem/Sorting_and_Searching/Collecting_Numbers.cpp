#include <bits/stdc++.h>
using namespace std;

int main()
{
  

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        if (k == 1)
        {
            bool fl = false;
            for (char c : s)
            {
                if (c == '1')
                {
                    fl = true;
                    break;
                }
            }

            if (fl)
            {
                cout << "NO"<<endl;
                continue;
            }
        }

        cout << "YES"<<endl;

        vector<int> p(n);

        for (int i = 0; i < n; i++)
            p[i] = i + 1;

        for (int i = 0; i < n; i += k)
        {
            int l = i;
            int r = min(i + k - 1, n - 1);
            reverse(p.begin() + l, p.begin() + r + 1);
        }

        for (int x : p)
            cout << x << " ";
        cout << endl;
    }
}