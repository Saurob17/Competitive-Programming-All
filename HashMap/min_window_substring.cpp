#include <bits/stdc++.h>
using namespace std;
string findMinWindowSubstring(string source, string target)
{
    unordered_map<char, int> mapT, mapS;
    for (char c : target)
    {
        mapT[c]++;
    }

    int strlen = INT_MAX;

    int matchCount = 0;
    vector<int> fans(2);

    for (int i = 0, j = 0; i < source.size(); i++)
    {

        char ch = source[i];
        if (mapT.find(ch) != mapT.end())
        {
            mapS[ch]++;
            if (mapS[ch] <= mapT[ch])
            {

                matchCount++;
            }
        }

        while (matchCount == target.size())
        {
            char chj = source[j];
            if (mapS.find(chj) != mapS.end())
            {
            }
            else if (mapS[chj] > mapT[ch])
            {
                mapS[chj]--;
            }
            else
            {
                if (i - j + 1 < strlen)
                {
                    strlen = i - j + 1;
                    fans[0] = i;
                    fans[1] = j;
                }
                mapS[chj]--;
                if (mapS[chj] < 0)
                {
                    mapS.erase(chj);
                }
                matchCount--;
            }
            j++;
        }
    }
    if (fans[0] == fans[1] && target.size() != 1)
    {
        return "";
    }
    return source.substr(fans[1], strlen);
}
string minWindow(string s, string t) {
    if (t.size() > s.size()) return "";

    unordered_map<char,int> need, have;
    for (char c: t) need[c]++;

    int required = need.size();
    int formed = 0;

    int l = 0, r = 0;
    int minLen = INT_MAX, start = 0;

    while (r < s.size()) {
        char c = s[r];
        have[c]++;

        if (need.count(c) && have[c] == need[c]) {
            formed++;
        } 

        while (formed == required) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }

            char leftChar = s[l];
            have[leftChar]--;
            if (need.count(leftChar) && have[leftChar] < need[leftChar]) {
                formed--;
            }
            l++;
        }
        r++;
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main()
{
    string source, target;
    cin >> source >> target;
   // string ans = findMinWindowSubstring(source, target);
    string ans = minWindow(source, target);
    cout << ans << endl;
}