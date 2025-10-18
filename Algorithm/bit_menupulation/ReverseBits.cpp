#include <bits/stdc++.h>
using namespace std;
long long reverseBitNum(long long n)
{
    vector<int> bit;
    while (n > 0)
    {
        bit.push_back(n & 1);
        n = n >> 1;
    }
    int size = bit.size();
    while (size < 32)
    {
        bit.push_back(0);
        size++;
    }
    long long ans = 0;

    for (int i = 0; i < 32; i++)
    {
        if (bit[i] == 1)
        {
            long long val = 1;
            val = val << (31 - i);
            ans += val;
        }
    }
    return ans;
}
int main()
{
    long long n;
    cin >> n;
    cout << reverseBitNum(n) << endl;
}