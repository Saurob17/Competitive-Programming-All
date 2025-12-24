#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int len = 0;
        bool invalid = false;

        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] == '\\')
            {

                if (i + 1 >= s.size())
                {
                    invalid = true;
                    break;
                }

                if (s[i + 1] == '\\')
                {
                    len++;
                    i++;
                }
                else if (s[i + 1] == '0')
                {

                    break;
                }
                else
                {

                    invalid = true;
                    break;
                }
            }
            else
            {

                len++;
            }
        }

        if (invalid)
            cout << "INVALID\n";
        else
            cout << len << "\n";
    }
    return 0;
}
