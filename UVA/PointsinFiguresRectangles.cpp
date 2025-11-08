#include <bits/stdc++.h>
using namespace std;
struct rec
{
    double left, right, top, buttom;
};

int main()
{
    vector<rec> AllRec;

    while (1)
    {
        char ch;
        if (!(cin >> ch))
            return 0;
        if (ch == '*')
        {
            break;
        }
        if (ch == 'r')
        {
            double x1, y1, x2, y2;
            rec r;
            cin >> x1 >> y1 >> x2 >> y2;

            r.left = min(x1, x2);
            r.right = max(x1, x2);
            r.buttom = min(y1, y2);
            r.top = max(y1, y2);
            AllRec.push_back(r);
        }
    }
    double x, y;
    int Point = 0;

    while (cin >> x >> y)
    {
        if (x == 9999.9 && y == 9999.9)
            break;
        Point++;

        bool isContain = false;

        for (int i = 0; i < AllRec.size(); i++)
        {
            if (x > AllRec[i].left && x < AllRec[i].right && y > AllRec[i].buttom && y < AllRec[i].top)
            {
                cout << "Point " << Point << " is contained in figure " << i + 1 << endl;
                isContain = true;
            }
        }
        if (!isContain)
        {
            cout << "Point " << Point << " is not contained in any figure" << endl;
        }
    }
}