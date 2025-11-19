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
        vector<long long> v(n);  long long sum = 0,total=0;
        for (int i = 0; i < n; i++){
             cin >> v[i];
             total+=v[i];
        }
           

      
        long long n1 = (long long)n, val = 1;

        while (n > 0)
        {
            long long to = n * (n1 + val);
            n--;
            val++;
            sum = max(sum, to);
        }

        
    }
}