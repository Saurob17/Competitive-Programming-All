#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;

    unordered_map<string, string> mp;

    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        mp[s1] = s2;
    }

    unordered_map<string, bool> path;

    for (auto it : mp)
    {
        string curr = it.first, curr2 = it.second;
        if (path.find(curr) == path.end())
        {
            path[curr] = true;
        }
        path[curr2] = false;

    }
    string start = "";
    for (auto it : path)
    {
        if (it.second == true)
        {
            start = it.first;
            break;
        }
    }

    string pa=start;

    while(mp.find(start)!=mp.end())
    {
        pa += "->" + mp[start];
        start=mp[start];
        
    }
    cout<<pa<<endl;


}