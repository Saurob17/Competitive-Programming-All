#include <bits/stdc++.h>
using namespace std;
int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int pidx = start - 1;
    for (int i = start; i < end; i++)
    {
        if (arr[i] < pivot)
        { pidx++;
            swap(arr[i], arr[pidx]);
           
        }
    }
    pidx++;
    swap(arr[pidx], arr[end]);
    return pidx;
}
void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pidx = partition(arr, start, end);
        quickSort(arr, start, pidx - 1);
        quickSort(arr, pidx + 1, end);
    }
}
int main()
{

    int a[] = {12, 24, 3, 44, 5};
    int n = 5;
    cout<<endl<<endl;
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}