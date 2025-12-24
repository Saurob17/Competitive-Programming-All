#include <bits/stdc++.h>
using namespace std;
void subsequense(vector<vector<int>> &v, vector<int> v1, vector<int> pus, int idx)
{
    if (idx >= v1.size())
    {
        if (pus.size() > 0)
        {
            v.push_back(pus);
        }
        return;
    }
    // exclude
    subsequense(v, v1, pus, idx + 1);

    // include
    pus.push_back(v1[idx]);
    subsequense(v, v1, pus, idx+1);
}
int main()
{

    vector<vector<int>> v;
    vector<int> v1 = {1, 2, 3};
    vector<int> pus;
    subsequense(v, v1, pus, 0);
    for (auto &seq : v) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << endl;
    }
}