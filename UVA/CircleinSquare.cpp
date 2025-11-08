#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int p = t;
    while (t--)
    {
        double red;
        cin >> red;

        double sqrAre = (2 * red) * (2 * red);
        double CirAre = (2 * acos(0.0)) * (red * red);
  cout << fixed << setprecision(2);

        cout << "Case " << p << ":" << sqrAre - CirAre << endl;
    }
}