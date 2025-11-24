// array roted
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

        vector<long long> v(n), u(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            u[i] = v[i];
        }
        sort(v.begin(), v.end());

        for(int i=0;i<n;i++){
        
            //v[0...n-1]<u[i] count 

            int count = lower_bound(v.begin(), v.end(), u[i]) - v.begin();
            cout<<count<<" ";
        }
        cout << endl;
        
    }
}