#include <bits/stdc++.h>
using namespace std;

long long cks(const vector<long long> &v, long long k)
{
    unordered_map<long long, long long>fq;
fq[0] = 1; 
    long long sm = 0, ans = 0;
    for (long long x : v)
    {
        sm += x;
        long long nd = sm - k;
        auto it =fq.find(nd);
        if (it !=fq.end())
            ans += it->second;
    fq[sm]++;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++){
             cin >> v[i];
        }
           
       
        long long k;
        cin >> k;
        cout << cks(v, k) << '\n';
    }

}
