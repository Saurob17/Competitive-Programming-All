#include <bits/stdc++.h>
using namespace std;
bool isPallindrom(string s)
{
    string s2 = s;
    reverse(s.begin(), s.end());
    return s2 == s;
}

void geatAllparts(string s, vector<string> &partition, vector<vector<string>> &ans)
{

    if (s.size() == 0)
    {
        ans.push_back(partition);
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {

        string part = s.substr(0, i + 1);
        if (isPallindrom(part))
        {
            partition.push_back(part);
            geatAllparts(s.substr(i + 1), partition, ans);
            partition.pop_back();
        }
    }
}
int main()
{
    
}