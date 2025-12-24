#include <bits/stdc++.h>
using namespace std;
string comput(string s)
{
    int o = 0, c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '_')
        {
            if (o <= c)
            {
                s[i] = '(';
                o++;
            }
            else
            {
                s[i] = ')';
                c++;
            }
        }
        else if(s[i]=='(')o++;
        else{
            c++;
        }
    }
    return s;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        /* code */
        int n;
        cin>>n;
        string s;
        cin >> s;
        string com = comput(s);
        stack<pair<char, int>> st;
        int sum = 0;
        int ind = 1;
        //cout<<com<<endl;
        for (auto c : com)
        {
            if (st.empty())
            {
                st.push({c, ind});
            }
            else
            {
                if (st.top().first == '(' && c == ')')
                {
                    sum += (ind - st.top().second);
                    st.pop();
                }
                else
                {
                    st.push({c, ind});
                }
            }
            ind++;
        }
        cout<<sum<<endl;
    }
}