#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       string s;
       cin>>s;

       int mc=0,n=s.size();

       for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1])mc++;
       }

       if(mc>2)cout<<"NO"<<endl;
       else cout<<"YES"<<endl;

    }
}