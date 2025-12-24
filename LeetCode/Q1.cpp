#include <bits/stdc++.h>
using namespace std;
int minOperations(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> m;
    for (auto it : nums)
    {
        m[it]++;
    }
    if (nums.size() == m.size())
        return 0;
    int c = 0;
    for (int i = 0; i < n; i++)
    {

        m[nums[i]]--;
        if (m[nums[i]] == 0)
        {
            m.erase(nums[i]);
        }
        if (i % 3 == 2)
        {
            c++;

           
            cout << endl;
            cout << i << ' ' << endl;
            if (m.size() == (n - (3 * c)))
                break;
        }
    }
    if (c == 0)
    {
        return 1;
    }
    return c;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int ans=minOperations(nums);
    cout<<ans<<endl;
}