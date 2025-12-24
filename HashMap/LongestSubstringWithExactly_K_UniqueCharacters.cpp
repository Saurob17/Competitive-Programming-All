#include <bits/stdc++.h>
using namespace std;
int longSubEx_K_Char(string s, int k)
{
    unordered_map<char, int> mp;

    int i = 0, j = 0;
    int formed = 0;
    int n = s.size();
    int ans = -1;
    while (i < n)
    {
        mp[s[i]]++;

        if (mp[s[i]] == 1)
        {
            formed++;
        }
        if (formed == k)
        {
            // store the answer
            ans = max(ans, i - j + 1);
        }
        if (formed > k)
        {
            while (formed!=k)
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                {
                    formed--;
                }
                j++;
                
            }
        }
        i++;
    }
    return ans;
}
int main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    cout << longSubEx_K_Char(s, k) << endl;
}