#include <bits/stdc++.h>
using namespace std;
set<vector<int>> com;
void findcombination(int idx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (target == 0)
    {
        com.insert(ds);
    }
    if (idx == arr.size() || target < 0)
    {
        return;
    }

    findcombination(idx, target - arr[idx], arr, ans, ds);
    ds.pop_back();
    findcombination(idx + 1, target, arr, ans, ds);
}
int main()
{
    int target = 7;
    vector<vector<int>> ans;
    vector<int> arr = {1, 2, 3, 6, 7};
    vector<int> ds;
    findcombination(0, target, arr, ans, ds);
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}