#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7;

bitset<MAXN / 2 + 1> isComposite;

void bitwiseSieve()
{
    isComposite.reset(); // সবাইকে prime ধরে নিচ্ছি

    for (int i = 3; i * i <= MAXN; i += 2)
    {
        if (!isComposite[i / 2])
        { // i prime হলে
            for (int j = i * i; j <= MAXN; j += 2 * i)
            {
                isComposite[j / 2] = 1; // composite mark
            }
        }
    }
}
bool isqrt(int n)
{
    int sq = sqrt(n);

    if (sq * sq == n)
        return true;
    return false;
}
bool isPrimex2plusy4(int n)
{

    for (int i = 0; i * i * i * i < n; i++)
    {

        if (isqrt(n - (i * i * i * i)))
            return 1;
    }
    return 0;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bitwiseSieve();

    vector<int>v(1e7+1,0);
    v[2]=1;



    for (int i = 3; i <= MAXN; i += 2)
    {
        if (!isComposite[i / 2])
        {
          if(isPrimex2plusy4(i)){
            v[i]=1;
          }
           
        }
       

    }
    for(int i=1;i<=MAXN;i++){
        v[i]+=v[i-1];
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin>>n;
        cout<<v[n]<<endl;
    }
}
