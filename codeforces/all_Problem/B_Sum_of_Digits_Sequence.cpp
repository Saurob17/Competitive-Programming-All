#include <bits/stdc++.h>
using namespace std;
#define ll long long

int sum_of_digits(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int32_t main()
{
    int n;
    cin >> n;
    int sum = 1;

    if (n < 2)
    {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 2; i <= n; i++)
    {
        
        int this_sum = sum_of_digits(sum);

       // cout << "this_sum: " << this_sum <<"  "<<sum<< endl;
        sum += this_sum;
        this_sum=sum;
    }
    cout << sum << endl;
}