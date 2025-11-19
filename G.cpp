#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        string s;
        cin >> s;
        int total = (int)s.size();

        int pos = s.find("\\0");
        // count /0 occurrences
        int co = 0;
        for (int i = 0; i + 1 < total; i++)
        {
            if (s[i] == '\\' && s[i + 1] == '0')
            {
                co++;
            }
        }

        int before;
        if (pos == string::npos)
        {
            before = total;
        }
        else
        {
            before = (int)pos;
        }
        cout << total-(co-1) << ' ' << before << '\n';
    }

    return 0;
}