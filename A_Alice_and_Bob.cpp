#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        bool inf = false, sup = false;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '>')
            {
                sup = true;
            }
            if (s[i] == '<' && sup)
            {
                inf = true;
            }
        }

        int cl = 0, f = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*' && s[i + 1] == '*')
            {
                inf = true;
            }

            if (f == 0 && (s[i] == '<' || s[i] == '*'))
            {
                cl++;
            }
            if (s[i] == '>')
            {
                f = 1;
            }

            if ( ((s[i] == '*' && s[i] == '<') || (s[i] == '>' && s[i + 1] == '*')))
            {
                inf = true;
            }
        }

        for(int i=0;i<n-1;i++){
               if ( ((s[i] == '*' && s[i+1] == '<') || (s[i] == '>' && s[i + 1] == '*')))
            {
                inf = true;
            }
        }
        int cg = 0, fl = 0;

        for (int i = n; i >= 0; i--)
        {
            if ((s[i] == '>' || s[i] == '*') && fl == 0)
            {
                cg++;
            }
            if (s[i] == '<')
                fl = 1;//*<
        }

        if (inf)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << max(cg, cl) << endl;
        }
    }
}