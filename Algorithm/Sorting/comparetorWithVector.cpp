#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{

    //if ture hoi then a b swap hoye jabe
    if (a < b)
        return false;
    else
        return true;
}
int main()
{

    vector<int> v;

    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end(), cmp);

    for(int i:v){

        cout<<i<<" ";

    }

}

// if(a<b) returin true;  a b swap hobe na

