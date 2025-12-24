#include<bits/stdc++.h>
using namespace std;
long long countAtMostK(string s, int k)
{
    unordered_map<char, int> mp;
    long long ans = 0;
    int j = 0;

    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;

        while (mp.size() > k)
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                mp.erase(s[j]);
            j++;
        }

        ans += (i - j + 1);
    }

    return ans;
}

long long countExactlyK(string s, int k)
{
    if (k == 0) return 0;
    return countAtMostK(s, k) - countAtMostK(s, k - 1);
}
int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    cout<<countExactlyK(s,k)<<endl;

}