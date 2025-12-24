#include <bits/stdc++.h>
using namespace std;
int sumOfOneTOn(int n)
{
    return (n * (n + 1)) / 2;
}
int LsubWotNonRepCHar(string s)
{
    unordered_map<char, int> mp;
    int n = s.size();
    int i = 0, j = 0;
    int ans = 0;
    while (i < n)
    {
        mp[s[i]]++;

        // duplicate found
        while (mp[s[i]] > 1)
        {
            mp[s[j]]--;
            j++;
        }

       // ans = max(ans, i - j + 1);
        for(int k=1;k<=(i - j + 1);k++)
        {
            ans+=sumOfOneTOn(k);
        }
      
        i++;
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << LsubWotNonRepCHar(s) << endl;
    return 0;
}