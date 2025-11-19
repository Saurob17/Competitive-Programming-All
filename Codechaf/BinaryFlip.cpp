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
        string s;
        cin >> s;
        int flp00 = 0, flp11 = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '0' && s[i + 1] == '0')
                flp00++;
            else if (s[i] == '1' && s[i + 1] == '1')
                flp11++;
        }
int dif=flp00-flp11;

if(dif<=0){
    cout<<0<<endl;
}else{
    cout<<(dif+1)/2<<endl;
}


        // vector<int> flip0(n, 0);
        // vector<int> flip1(n, 0);
        // for (int i = 1; i < n; i++)
        // {
        //     flip0[i] = flip0[i - 1];
        //     flip1[i] = flip1[i - 1];
        //     if (s[i] == '0' && s[i - 1] == '0')
        //         flip0[i]++;
        //     else if (s[i] == '1' && s[i - 1] == '1')
        //         flip1[i]++;
        // }

        

        // int fli101 = 0;
        // for (int i = 1; i < n - 1; i++)
        // {
        //     if (s[i] == '1' && s[i - 1] == '0' && s[i + 1] == '1')
        //     {
        //         fli101 += flip0[i - 1];
        //     }
        // }


        // if (flp11 >= flp00)
        // {
        //     cout << 0 << endl;
        // }
        // else
        // {
        // }
    }
}