#include <bits/stdc++.h>

using namespace std;
void subSet(vector<int> &v, int index, vector<int> &ans)
{
//TC-> O(2^n * n)
    if (index == v.size())
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    // include

    ans.push_back(v[index]);

    subSet(v, index + 1, ans);
    // exclude
    ans.pop_back();
    subSet(v, index + 1, ans);
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> ans;
    subSet(v, 0, ans);
}