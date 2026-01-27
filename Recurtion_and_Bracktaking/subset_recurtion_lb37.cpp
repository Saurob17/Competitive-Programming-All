#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> num, vector<int> output, int index, vector<vector<int>> &ans)
{
    if (index >= num.size())
    {
        ans.push_back(output);
        return;
    }
    //exclude
    solve(num, output, index + 1, ans);

    //include
    int element=num[index];
    output.push_back(element); 
    solve(num,output,index+1,ans);
 

}
 
int main()
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    vector<int> v = {1, 2, 3};
    solve(v, output, index, ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
