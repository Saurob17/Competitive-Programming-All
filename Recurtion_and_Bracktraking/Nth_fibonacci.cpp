#include <bits/stdc++.h>
using namespace std;
int Nth_fibonacci(int n)
{

    if (n == 1 || n == 0)
    {
        // cout<<n<<" ! ";
        return n;
    }
    return Nth_fibonacci(n - 1) + Nth_fibonacci(n - 2);
  
}

int main()
{
    int n;
    cin >> n;
    cout << Nth_fibonacci(n);
} 