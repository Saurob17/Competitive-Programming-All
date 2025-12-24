#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// typedef __int128 lll;

void solve()
{
    string str;
    cin >> str;
    int n = str.length();
    set<char> s;
    vector<char> stk;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            stk.push_back(str[i]);
        }
        else if (str[i] == ')')
        {
            while (stk.back() != '(')
            {
                s.erase(stk.back());
                stk.pop_back();
            }
            stk.pop_back();
        }
        else
        {
            if (s.count(str[i]) == 1)
            {
                cout << "No\n";
                return;
            }
            s.insert(str[i]);
            stk.push_back(str[i]);
        }
    }
    cout << "Yes\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int testCases = 1;
    // cin >> testCases;
    while (testCases--)
    {
        solve();
    }
}