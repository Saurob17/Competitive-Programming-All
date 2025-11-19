#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;

        vector<long long> b(n);

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        int ans = 0;
        int st=0;

        sort(b.begin(),b.end());
        for(int i=n-1;i>=0;i--){
            if((b[i]<<st)>c){
                continue;
            }
            else{
                ans++;
                st++;
            }
        }
        cout<<n-ans<<endl;
       
    }
}