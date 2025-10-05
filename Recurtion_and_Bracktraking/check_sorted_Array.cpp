#include <bits/stdc++.h>
using namespace std;
bool check_sorted(int n, vector<int>v)
{
  
    if (n < 2)
    {
        return true;
    }
    if (v[n - 1] < v[n - 2])
    {
        //cout << v[n - 1] << " d " << v[n - 2];
        return false;
    }
  return  check_sorted(n - 1, v);
}

int main()
{
    int n;
    cin >> n;
   vector<int>v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    bool is_true = check_sorted(n, v);

    if (is_true)
    {
        cout << "array is sorted";
    }
    else
    {
        cout << "array is not sorted";
    }
}