#include <bits/stdc++.h>
using namespace std;
void print_subSet(vector<int> &v, vector<int> &ans, int n, int i)
{
    if (i == n)
    {
        for (auto it : ans)
        {
            cout << it << " "

                ;
        }

        cout << endl;
        return;
    }
    ans.push_back(v[i]);
    print_subSet(v, ans, n, i + 1);
    ans.pop_back();
    int index = i+1;

    while(index<n && v[index]==v[i]){
        index++;
    }

    print_subSet(v, ans, n, index);


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

    vector<int> ans;
    print_subSet(v, ans, n, 0);
}