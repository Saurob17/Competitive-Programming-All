#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 1e8;
 
bitset<MAXN / 2 + 1> isComposite;
 
void bitwiseSieve()
{
    isComposite.reset(); 
    for (int i = 3; i * i <= MAXN; i += 2)
    {
        if (!isComposite[i / 2])
        { // i prime à¦¹à¦²à§�
            for (int j = i * i; j <= MAXN; j += 2 * i)
            {
                isComposite[j / 2] = 1; // composite mark
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    bitwiseSieve();
    int cnt = 1;
    cout << 2 << '\n';
    for (int i = 3; i <= MAXN; i += 2)
    {
        if (!isComposite[i / 2])
        {
            cnt++;
            if (cnt % 100 == 1)
            {
                cout << i << '\n';
            }
        }
    }
 
    return 0;
}
 