#include <bits/stdc++.h>
using namespace std;
//TC->O(n!*n)
void allPurmutation(int indx, vector<vector<int>> &ans, vector<int> &v)
{

    if (indx == v.size())
    {
        ans.push_back(v);
        return;
    }

    for (int i = indx; i < v.size(); i++)
    {
        swap(v[indx], v[i]);
        allPurmutation(indx + 1, ans, v);
        swap(v[indx], v[i]);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<vector<int>> ans;
    allPurmutation(0,ans,v);
    for (auto it : ans)
    {
        for(int i=0;i<n;i++){
            cout<<it[i]<<" ";
             
        }
        cout<<endl;
    }
}