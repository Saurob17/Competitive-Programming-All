// 

#include <bits/stdc++.h>
using namespace std;

int SmalStr(string s)
{
    unordered_set<char> set;
    unordered_map<char, int> mp;
    int n = s.size();
    for (auto c : s)
        set.insert(c);
    int i = -1, j = -1;
    int ans = s.size();

    while (true)
    {
        bool f1 = false;
        bool f2 = false;
        while (i < (int)s.size()-1 && mp.size() < set.size())
        {
            i++;
            char ch = s[i];
            if (mp.find(ch) != mp.end())
            {
                mp[ch]++;
            }
            else
            {
                mp[ch] = 1;
            }
            f1 = true;
        }

        while (j < i && mp.size() == set.size())
        {
            ans = min(ans, i - j);
            j++;
            char ch = s[j];
            if (mp[ch] == 1)
            {
                mp.erase(ch);
            }
            else
            {
                mp[ch]--;
            }
            f2 = true;
        }
        if (f1 == false && f2 == false)
        {
            break;
        }
    }
    return ans;
}
//LongestSubstringWithoutRepeatingCharacters.cpp
//cpp name 
//smallest_SubStrOfStrContainAllUniqChar.cpp

int SmalStr(string s)
{
    unordered_set<char> allChars(s.begin(), s.end());
    int need = allChars.size();

    unordered_map<char,int> mp;

    int n = s.size();
    int i = 0, j = 0;
    int formed = 0;
    int ans = INT_MAX;

    while (i < n)
    {
        mp[s[i]]++;
        if (mp[s[i]] == 1) formed++;

        while (formed == need)
        {
            ans = min(ans, i - j + 1);

            mp[s[j]]--;
            if (mp[s[j]] == 0) formed--;

            j++;
        }
        i++;
    }
    return ans;
}

using namespace std;
int main()
{

    string s;
    cin >> s;
    cout << SmalStr(s) << endl;
    return 0;
}