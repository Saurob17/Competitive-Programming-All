#include <bits/stdc++.h>
using namespace std;
vector<int> idx(vector<int> v, int n)
{
    stack<int> st;
    vector<int> ans;
    st.push(1);
    for (int i = 0; i < n; i++)
    {

        if (st.empty())
        {
            ans.push_back(0);
        }
        else{
            while (!st.empty() && v[st.top()-1]>=v[i])
            {

           st.pop();

            }
            if(st.empty()){
                ans.push_back(0);
                st.push(i+1);
            }
            else{
                ans.push_back(st.top());
                st.push(i+1);
            }
            
            
        }
    }

    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>ans=idx(v,n);
    for(auto it:ans){
        cout<<it<<" ";
    }
}