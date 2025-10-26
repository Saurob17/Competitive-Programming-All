// http://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/

#include <bits/stdc++.h>
using namespace std;
int counttriple(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prefixorx(n + 1, 0);

    for (int i = 1; i <= n; i++)
        prefixorx[i] = prefixorx[i - 1] ^ arr[i - 1];

   vector<long long> m(1e4 + 1, LONG_LONG_MIN);
    int ans = 0;

    for (int i = 0; i <= n; i++)
    {
        cout<<prefixorx[i]<<" k "<<m[prefixorx[i]]<<" m "<<i<<"\n";
        if(m[prefixorx[i]]!=LONG_LONG_MIN)
        {
            ans+= (i - m[prefixorx[i]] );
          
        }
        else{
               m[prefixorx[i]] = i;
        }
     
    }
    return ans;
}

int main()

{
int n;
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
cout<<counttriple(arr);


}