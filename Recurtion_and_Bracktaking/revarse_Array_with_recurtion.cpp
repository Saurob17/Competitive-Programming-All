#include <bits/stdc++.h>
using namespace std;
void revarsr_array(int arr[], int n, int i)
{
    if (i >= (n / 2))
        return ;
    swap(arr[i], arr[n - i - 1]);
    revarsr_array(arr, n, i + 1);
}
int main()
{
    int arr[] = {5, 4, 2, 1};
    revarsr_array(arr, 4, 0);
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
}