#include <bits/stdc++.h>
using namespace std;
void findcombination(int idx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
{
    if (idx == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    if(arr[idx]<=target){
        ds.push_back(arr[idx]);
        findcombination(idx,target-arr[idx],arr,ans,ds);
        ds.pop_back();
    }
    findcombination(idx+1,target,arr,ans,ds);
}
int main()
{
    int target=7;
    vector<vector<int>>ans;
    vector<int>arr={1,2,3,6,7};
    vector<int>ds;
    findcombination(0,target,arr,ans,ds);
    for(auto it:ans){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }

}