#include <bits/stdc++.h>
using namespace std;

vector<long long> primeFactors(long long n)
{
    vector<long long> v;
    // Step 1: divide by 2
    while (n % 2 == 0)
    {
        v.push_back(2);
        n /= 2;
    }

    // Step 2: divide by odd numbers
    for (long long i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            v.push_back(i);
            n /= i;
        }
    }

    // Step 3: if remaining n > 2, it's prime
    if (n > 2)
        v.push_back(n);

        return v;
}
int oneTONsum(int n)
{
    return (n * (n + 1)) / 2;
}
int binrary(int n)
{
    int ans, l, r, mid;

    l = 1, r = n;
    while (l <= r)
    {
        mid = (l + r) / 2;
        int an = oneTONsum(mid);
        if (an <= n)
        {
            ans = mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}
int main()
{
    long long n;
    cin >> n;
    vector<long long> v;
    v = primeFactors(n);
    map<long long, int> mp;
    for (auto it : v)
    {
        mp[it]++;
        
    }
    int ans=0;

    for(auto it:mp){
        ans+=binrary(it.second);
    }
    cout<<ans;

   // cout<<binrary(15)<<" "<<binrary(16);

}
