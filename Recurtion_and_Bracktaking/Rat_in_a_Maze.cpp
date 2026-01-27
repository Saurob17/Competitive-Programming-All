#include <bits/stdc++.h>
using namespace std;
void findPath(vector<vector<int>> &mat, int r, int c, string path,
              vector<string> &ans, vector<vector<bool>> &vis)
{
    int n = mat.size();
    if (r < 0 || c < 0 || c >= n || r >= n || mat[r][c] == 0 || vis[r][c] == true)
    {
        return;
    }

    if (c == n - 1 && r == n - 1)
    {
        ans.push_back(path);
        return;
    }
    vis[r][c] = true;
    findPath(mat, r + 1, c, path + 'D', ans, vis); // dowen
    findPath(mat, r - 1, c, path + 'U', ans, vis); // up
    findPath(mat, r, c + 1, path + 'R', ans, vis); // right
    findPath(mat, r, c - 1, path + 'L', ans, vis); // left

    vis[r][c] = false;
}


int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));

    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    findPath(mat, 0, 0, "", ans, vis);
    if (ans.size() == 0)
    {
        cout << "No Path exist" << endl;
    }
    else
    {
        for (auto it : ans)
        {
            cout << it << endl;
        }
    }
    return 0;
}