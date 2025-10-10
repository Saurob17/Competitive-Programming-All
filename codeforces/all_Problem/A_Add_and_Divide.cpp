#include <bits/stdc++.h>
using namespace std;
#define int long long
int logn(int n, int b)
{
    int ans = 0;
    while (n > 0)
    {
        ans++;
        n = n / b;
    }
    return ans;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;

        cin >> a >> b;
        int ans = 0;
        if(b==1){
            ans++;
            b++;
        }

        int curr=logn(a,b);

        while(1){
            if(logn(a,b+1)<curr){

                  b++;
                ans++;
                curr=logn(a,b);

            }
            else{
                break;
            }
        }
//cout<<" t "<<curr<<endl;
        while (a>0){
            a/=b;
            ans++;
        }
        cout<<ans<<endl;
     
       
    }
}