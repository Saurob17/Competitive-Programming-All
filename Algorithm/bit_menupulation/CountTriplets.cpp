// http://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/

#include <bits/stdc++.h>
using namespace std;
int counttriple(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prefixorx(n + 1, 0);

    for (int i = 1; i <= n; i++)
        prefixorx[i] = prefixorx[i - 1] ^ arr[i - 1];

    map<int, int> mp;
    int ans = 0;

    for (int i = 0; i <= n; i++)
    {
        if (mp.count(prefixorx[i]))
        {
            ans += i - 1;
        }
        mp[prefixorx[i]] = i;
    }
    return ans;
}

int main()
{
    map<char, int> brk;
    int q;
    cin >> q;
    int siz = 0;  vector<char> st;
    int cloIn=-1;
    while (q--)
    {
      
        int typ;
        cin >> typ;
        if (typ == 1)
        {
            char c;
            cin >> c;
            st.push_back(c);
            brk[c]++;
            siz++;

            if(brk[')']>brk['('] && cloIn==-1){
                cloIn=siz;
            }

            if (brk[')'] == brk['('] && cloIn==-1)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
           
            if(siz==0) {
                cout<<"Yes"<<endl;
                continue;
            }
            brk[st[siz- 1]]--;
            siz--;
            st.pop_back();
            if(cloIn>siz){
                cloIn=-1;
            }
            if (brk[')'] == brk['('] && cloIn==-1)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
}