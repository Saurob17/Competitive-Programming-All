// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     if (!(cin >> t)) return 0;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<long long> a(n);
//         for (auto &x : a) cin >> x;

//         map<long long, int> cnt;
//         for (auto x : a) cnt[x]++;

//         long long S = 0;
//         vector<long long> ans;
//         ans.reserve(n);

//         for (int i = 0; i < n; ++i) {
//             long long pick;
//             if (cnt.size() == 1 && cnt.begin()->first == S) {
//                 pick = S;
//             } else {
//                 auto it = prev(cnt.end());
//                 if (it->first != S) {
//                     pick = it->first;
//                 } else {
//                     if (cnt.size() >= 2) {
//                         auto jt = it; --jt; // second largest
//                         pick = jt->first;
//                     } else {
//                         pick = it->first; // forced
//                     }
//                 }
//             }
//             ans.push_back(pick);
//             if (--cnt[pick] == 0) cnt.erase(pick);
//             S += pick;
//         }

//         for (int i = 0; i < n; ++i) {
//             if (i) cout << ' ';
//             cout << ans[i];
//         }
//         cout << '\n';
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     // int n, x;
    // cin >> n;
    // vector<int> a(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }
    // bool flag = false;
    // int fs=0, sc=0;
    // for (int i = 0; i < n-1; i++)
    // {
    //     for (int j = i+1; j < n; j++)
    //     {
    //         if (!((a[j] % a[i]) & 1))
    //         {
    //             flag = true;
    //             fs=a[i];
    //             sc=a[j];//lzjvlkdsjldsfl
    //             break;
    //         }
    //     }
    // }
    // if(flag){
    //     cout<<fs<<" "<<sc<<endl;
    // }
    // else{
    //     cout<<-1<<endl;
    // }

    int t;
    cin >> t;
    while (t--)
    {
        // int n, m;
        // cin >> n >> m;
        // vector<int> v, b(m), c(m);

        // for (int i = 0; i < n; i++)
        // {
        //     int x;
        //     cin >> x;
        //     v.push_back(x);
        // }
        // for (int i = 0; i < m; i++)
        // {
        //     cin >> b[i];
        // }
        // for (int i = 0; i < m; i++)
        // {
        //     cin >> c[i];
        // }

        // // max of v
        // int mx = *max_element(v.begin(), v.end());

        // for (int i = 0; i < m; i++)
        // {
        //     if (c[i] > 0 && mx>=b[i])
        //     {
        //         v.push_back(max(mx, c[i]));
        //         mx=max(mx,c[i]);
        //     }
        // }
        // sort(v.begin(), v.end());
        // sort(b.begin(), b.end());
        // int le = v.size();
        // int count = 0;
        // int it = 0, nn = 0;

        // while (it < m && nn < le)
        // {
        //     if (v[nn] >= b[it])
        //     {
        //         count++;
        //         it++;
        //         nn++;
        //     }
        //     else
        //     {
        //         nn++;
        //     }
        // }
        // cout << count << endl;

        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        swap(a[0],a[n-1]);
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";    
        }
        cout << endl;
    }
}
