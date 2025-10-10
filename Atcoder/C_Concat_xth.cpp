#include <bits/stdc++.h>
using namespace std;

void genarateAll(vector<string> &str, vector<string> &ans, int n, int k, string currStr, int depth)
{

    if (depth == k)
    {
        ans.push_back(currStr);

        return;
    }

    for (int i = 0; i < n; i++)
    {

        genarateAll(str, ans, n, k, currStr + str[i], depth + 1);
        
    }
}

int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<string> str(n);

    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    vector<string> ans;

    genarateAll(str, ans, n, k, "", 0);
    sort(ans.begin(), ans.end());
    cout << ans[x - 1] << endl;
    return 0;
}