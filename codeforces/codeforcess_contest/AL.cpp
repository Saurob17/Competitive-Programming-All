#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(const vector<int> &v) {
    int n = v.size();
    int num = 0;
    for (int i = 0; i < n; i++) {
        num = num * 2 + v[i]; // left shift + add bit
    }
    return num;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n,f=0;
        cin>>n;
        vector<int> v;
        int n2 = n;
        while (n2 > 0)
        {
            if (n2 & 1)
            {
                v.push_back(1);
            }
            else
            {
                v.push_back(0);
            }
            n2 /= 2;
        }
        vector<int> sn;
        std::reverse(v.begin(), v.end());
        int cnt = 0, idx = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == 1)
                cnt++;
            if (cnt == 2 && f == 0)
            {

                f = 1;
                v[i] = 0;
                sn.push_back(1);
            }
            else if (cnt > 1)
            {
                if (v[i] == 0)
                {
                    v[i] = 1;
                    sn.push_back(1);
                }
                else
                {
                    sn.push_back(0);
                }
            }
        }
        
        cout<<endl;
    }
}//
    // // k is even: use k-2 copies of n and a best pair (x,y) with x^y = n, x,y <= n maximizing sum
    // int msb = 31 - __builtin_clz(n); // since n >= 1
    // int M = 1 << msb;                // highest power of two <= n
    // int r = n - M;
    // vector<int> ans; ans.reserve(k);
    // for (int i = 0; i < k - 2; ++i) ans.push_back(n);
    // if (r == 0) {
    //     ans.push_back(n);
    //     ans.push_back(0);
    // } else {
    //     int h = 31 - __builtin_clz(r);
    //     int z = (1 << h) - 1;
    //     int x = M + z;
    //     int y = r ^ z;
    //     ans.push_back(x);
    //     ans.push_back(y);
    // }
    // for (int i = 0; i < k; ++i) cout << ans[i] << (i + 1 == k ? '\n' : ' ');