#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double l;
        cin >> l;

        double w = l * 0.6;
        double rad = l * 0.2;
        double pi = acos(-1);

        double CirAre = pi * rad * rad;
        double GreAre = (l * w) - CirAre;

        cout << fixed << setprecision(2);
        cout << CirAre << " " << GreAre << endl;
    }
    return 0;
}
