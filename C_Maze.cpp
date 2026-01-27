#include <bits/stdc++.h>
using namespace std;
int k;
void dfs(int n, int m, int i, int j, vector<string> &v)
{
v[i][j]='p';
    if ((i - 1) >= 0 && v[i - 1][j] == '.')
    {
        dfs(n, m, i - 1, j, v);
    }
    if ((i + 1) < n && v[i + 1][j] == '.')
    {
        dfs(n, m, i + 1, j, v);
    }

    if ((j - 1) >= 0 && v[i][j - 1] == '.')
    {
        dfs(n, m, i, j - 1, v);
    }

    if ((j + 1) < m && v[i][j + 1] == '.')
    {
        dfs(n, m, i, j + 1, v);
    }

    if (k >= 1)
    {
        v[i][j] = 'X';
        k--;
    }
}
int main()
{
    int n, m;
    cin >> n >> m >> k;
    vector<string> v;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v.push_back(s);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '.')
            {
                dfs(n, m, i, j, v);
            }
            if(v[i][j]=='p'){
                cout<<'.';
            }
            else
            cout << v[i][j];
        }
        cout << endl;
    }
}