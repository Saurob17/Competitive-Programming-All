#include <bits/stdc++.h>
using namespace std;
int BS(int str, int end, int trg, vector<int>&v)
{

    if (str > end)
    {
        return -1;
    }
    int mid = (str + end) / 2;
    if (v[mid] == trg)
    {
        return mid;
    }

    if(v[mid]<trg){
      return  BS(mid+1,end,trg,v);
    }
    else{
     return  BS(str, mid - 1, trg, v);
    }
   
}

int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int trg;
    cin >> trg;
    cout << BS(0, n - 1, trg, v);
}