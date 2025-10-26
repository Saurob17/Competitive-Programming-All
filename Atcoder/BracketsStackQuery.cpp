// http://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/

#include <bits/stdc++.h>
using namespace std;

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