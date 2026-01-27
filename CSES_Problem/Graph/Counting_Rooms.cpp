#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, int n, int m, vector<vector<char>> &grid)
{
    grid[i][j] = '#';
    // left
    if (i - 1 >= 0 && grid[i - 1][j] == '.')
    {
        dfs(i - 1, j, n, m, grid);
    }
    // right
    if (i + 1 < n && grid[i + 1][j] == '.')
    {
        dfs(i + 1, j, n, m, grid);
    }
    if (j + 1 < m && grid[i][j + 1] == '.')
    {
        dfs(i, j + 1, n, m, grid);
    }
    if (j - 1 >= 0 && grid[i][j - 1] == '.')
    {
        dfs(i, j - 1, n, m, grid);
    }
}
int main()
{
    int n, m;
    cin >> n>>m;
    vector<vector<char>> grid(n);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        vector<char> tem(m);

        for (int j = 0; j < m; j++)
        {
            cin >> tem[j];
        }
        grid[i] = tem;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                count++;
                dfs(i, j, n, m, grid);
            }
        }
    }
    cout<<count;
}