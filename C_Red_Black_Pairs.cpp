#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s, s1;
        cin >> s >> s1;
        int ned = 0;
        int i = 0;
        while (i < n)
        {
            /* code */ 
            if (i < (n - 1))
            {
                if ((s[i] == s[i + 1] && s1[i] == s1[i + 1] ) ||  ( s[i]==s1[i] && s[i+1]==s1[i+1]))
                {
                   i+=2;
                }
               else if(s[i]!=s1[i]){
                ned++;
                i+=1;
               }
               else{
                i+=1;
               }
                
            }
            else{
                if(s[i]!=s1[i]){
                    ned+=1;
                   
                }
                 i+=1;
            }
        }
        
        cout<<ned<<endl;
    }
}