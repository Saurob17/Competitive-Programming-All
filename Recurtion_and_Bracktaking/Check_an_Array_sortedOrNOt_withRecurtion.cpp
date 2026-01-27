#include <bits/stdc++.h>
using namespace std;
bool check(vector<int>&v,int n)
{
if(n==0 || n==1){
    return true;
}
return (v[n-1]>=v[n-2]) && check(v,n-1) ;
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
   cout<< check(v,n);

}