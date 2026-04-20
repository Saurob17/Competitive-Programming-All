#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
    }

    sort(v.begin(),v.end());


    long long target=1;
    for(int i=0;i<n;i++){
        if(v[i]>target){
            break;
           // cout<<target<<" ";
        }
        //cout<<target<<"h  ";
     
            target +=v[i];
  
    }
    cout<<endl;
    cout<<target<<endl;

}