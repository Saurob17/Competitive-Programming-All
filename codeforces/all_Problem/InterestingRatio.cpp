#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<long> s(1e7 + 1);
    for (int i = 2; i < 1e7 + 1; i++)
        if (s[i] == 0)
        {
            for (int j = i; j < 1e7 + 1; j += i)
                s[j]++;
        }


    for (int i = 0; i < 12; i++)
    {
        cout << s[i] << " ";
    }

    cout<<endl;
    for (int i = 0; i < 1e7; i++)
        s[i + 1] += s[i];
    int t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << s[n] << '\n';
    }
}
