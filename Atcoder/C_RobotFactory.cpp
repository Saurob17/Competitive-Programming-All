#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, b, k;
    cin >> h >> b >> k;

    vector<int> hp, bp;
    for (int i = 0; i < h; i++)
    {
        int x;
        cin >> x;
        hp.push_back(x);
    }

    for (int i = 0; i < b; i++)
    {
        int y;
        cin >> y;
        bp.push_back(y);
    }

    sort(hp.begin(), hp.end());
    sort(bp.begin(), bp.end());
    bool poss = false;
    int bl = 0, hl = 0, count = 0;

    while (bl < b && hl < h)
    {
        if (bp[bl] >= hp[hl])
        {
            count++;
            bl++;
            hl++;
        }
        else
        {
            bl++;
        }
        if (count == k)
        {
            poss = true;
            cout << "Yes"<<endl;
                break;
        }
    }
    if (!poss)
    {
        cout << "No"<<endl;
    }
}