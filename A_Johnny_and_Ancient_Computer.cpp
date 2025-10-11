#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;

        if(a==b){
            cout<<0<<endl;
            continue;
        }

        int ra,rb;
       int a2=0,b2=0;
        while(a%2==0){
            a/=2;
            a2++;

        }
        while(b%2==0){
            b/=2;
            b2++;
        }

        if(a!=b){
            cout<<-1<<endl;
        }
        else{
            cout<<ceil(abs(a2-b2)/3.0)<<endl;
        }

    }
    return 0;
}