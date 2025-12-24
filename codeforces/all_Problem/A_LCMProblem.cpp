#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string s = "";
        for (int i = 0; i < n; i++)
        {
            string a;
            cin >> a;
            if (s.empty())
            {
                s = a;
            }
            else
            {
                if (a + s < s + a)
                {
                    s = a + s;
                }
                else
                {
                    s = s + a;
                }
            }
        }
        cout << s << endl;
    }
}
