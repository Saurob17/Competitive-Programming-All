#include <bits/stdc++.h>
using namespace std;
struct RecCir
{
    char typ;
    double left, right, top, buttom;
};

int main()
{

    RecCir a;
    vector<RecCir> All;

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
            double x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            a.left = min(x1, x2);
            a.right = max(x1, x2);
            a.top = max(y1, y2);
            a.buttom = min(y1, y2);
            a.typ = ch;
            All.push_back(a);
        }
        else if (ch == 'c')
        {
            double x, y, rad;
            cin >> x >> y >> rad;
            a.left = x;
            a.right = y;
            a.top = rad;  // cir redious
            a.buttom = 0; // buggas
            a.typ = ch;
            All.push_back(a);
        }
    }
    int point = 0;
    double x, y;
    while (cin >> x >> y)
    {
        if (x == 9999.9 && y == 9999.9)
            break;
        point++;
        bool isContain = false;
        for (int i = 0; i < All.size(); i++)
        {

            if (All[i].typ == 'r')
            {
                if (x > All[i].left && x < All[i].right && y > All[i].buttom && y < All[i].top)
                {
                    cout << "Point " << point << " is contained in figure " << i + 1 << endl;
                    isContain = true;
                }
            }
            else if (All[i].typ == 'c')
            {

                double dis = sqrt(((x - All[i].left) * (x - All[i].left)) + ((y - All[i].right) * (y - All[i].right)));
                if (dis < All[i].top)
                {

                    cout << "Point " << point << " is contained in figure " << i + 1 << endl;
                    isContain = true;
                }
            }
        }
        if (!isContain)
        {
            cout << "Point " << point << " is not contained in any figure" << endl;
        }
    }
}