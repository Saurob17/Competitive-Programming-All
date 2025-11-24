#include <bits/stdc++.h>
using namespace std;
int size(unordered_map<string, unordered_set<string>> &mp, const string &man, map<string, int> &ans)
{

    if (mp.find(man) == mp.end())
    {
        ans[man] = 0;
        return 1;
    }
    int sz = 0;

    for (const string &emp : mp[man])
    {
        int curr_size = size(mp, emp, ans);
        sz += curr_size;
    }
    ans[man] = sz;
    return sz + 1;
}

int main()
{

    int n;
    cin >> n;
    string ceo = "";

    unordered_map<string, unordered_set<string>> mp;

    for (int i = 0; i < n; i++)
    {
        string emp, man;
        cin >> emp >> man;
        if (man == emp)
        {
            ceo = man;
            continue;
        }
        mp[man].insert(emp);
    }

    map<string, int> ans;
    size(mp, ceo, ans);

    for (auto emp : ans)
    {
        cout << emp.first << " " << emp.second << endl;
    }
}