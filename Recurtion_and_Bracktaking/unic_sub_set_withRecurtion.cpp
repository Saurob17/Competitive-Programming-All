#include <bits/stdc++.h>
using namespace std;
void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, vector<int> &freq)
{
    if (ds.size() == nums.size())
    { // Base case: when permutation is complete
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!freq[i])
        { // If the element nums[i] is not used in the permutation
            ds.push_back(nums[i]);
            freq[i] = 1; // Mark nums[i] as used
            recurPermute(ds, nums, ans, freq);
            freq[i] = 0; // Backtrack: Mark nums[i] as unused
            ds.pop_back();
        }
    }
}
int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans;          // Stores all permutations
    vector<int> ds;                   // Current permutation
    vector<int> freq(nums.size(), 0); // Frequency array initialized to 0

    recurPermute(ds, nums, ans, freq);
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}