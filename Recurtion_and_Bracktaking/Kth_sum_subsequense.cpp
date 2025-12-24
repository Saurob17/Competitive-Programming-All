#include <bits/stdc++.h>
using namespace std;
void print_subsequens_sumK(int idx, vector<int> &v, int s, int sum, int arr[], int n)
{
    if (idx >= n)
    {
        if (s == sum)
        {
            for (auto it : v)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    v.push_back(arr[idx]);
    s += arr[idx];
    print_subsequens_sumK(idx + 1, v, s, sum, arr, n);
    s -= arr[idx];
    v.pop_back();
    print_subsequens_sumK(idx + 1, v, s, sum, arr, n);
}

int print_subsequens_sumK_n_Times(int idx, vector<int> &v, int s, int sum, int arr[], int n)
{
    if (idx >= n)
    {
        if (s == sum)
        {

            return 1;
        }
        return 0;
    }
    v.push_back(arr[idx]);
    s += arr[idx];
    int l = print_subsequens_sumK_n_Times(idx + 1, v, s, sum, arr, n);
    s -= arr[idx];
    v.pop_back();
    int r = print_subsequens_sumK_n_Times(idx + 1, v, s, sum, arr, n);
    return l + r;
}

bool print_subsequens_sumK_oneTime(int idx, vector<int> &v, int s, int sum, int arr[], int n)
{
    // condition
    if (idx >= n)
    {
        if (s == sum)
        {
            for (auto it : v)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    v.push_back(arr[idx]);
    s += arr[idx];

    if (print_subsequens_sumK_oneTime(idx + 1, v, s, sum, arr, n) == true)
    {
        return true;
    }

    s -= arr[idx];
    v.pop_back();
    if (print_subsequens_sumK_oneTime(idx + 1, v, s, sum, arr, n) == true)
    {
        return true;
    }

    return false;
}

int main()
{
    int arr[] = {2, 2, 2};
    vector<int> v;
    int n = 3;
    cout<<print_subsequens_sumK_n_Times(0, v, 0, 2, arr, n)<<endl;
    //print_subsequens_sumK(0, v, 0, 2, arr, n);
}