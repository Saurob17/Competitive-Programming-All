#include <bits/stdc++.h>
using namespace std;
int Nth_factorial(int n)
{
    if (n == 0)
    {

        return 1;
    }
    int fact = n * Nth_factorial(n - 1);

    cout << fact << " ";
    return fact;
}

int main()
{
    int n;
    cin >> n;
   Nth_factorial(n);
}