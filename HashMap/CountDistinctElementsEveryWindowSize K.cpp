#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    unordered_map<int, int> mp;
    vector<int> res;

    for (int i = 0; i < k; i++)
    {
        mp[arr[i]]++;
    }
    res.push_back(mp.size());

    for (int i = k; i < n; i++)
    {

        mp[arr[i - k]]--;
        if (mp[arr[i - k]] == 0)
        {
            mp.erase(arr[i - k]);
        }
        mp[arr[i]]++;
        res.push_back(mp.size());
    }

    for (int val : res)
    {
        cout << val << " ";
    }
}