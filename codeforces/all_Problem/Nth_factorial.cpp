#include <bits/stdc++.h>
using namespace std;
const long long n= 1000000;
vector<long long> fact(n + 1, 0);

long long factro(long long x)
{

    if (fact[x] != 0)
        return fact[x];

    if (x == 0 )
    {
       

        fact[x] = 1;
        
        return 1;
    }
    else if(x==1)
    {
        fact[x] = 1;
        return 1;
    }
    else
    {
        fact[x] = x * factro(x - 1);
        return fact[x];
    }
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;

        factro(x);
        cout<< fact[x] << endl;
    }


}
