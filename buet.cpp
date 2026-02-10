
// #include<bits/stdc++.h>
// using namespace std;

// int fix = 0;

// deque<pair<int, int>>dq;
// set<pair<int, int>>st;

// int x = 1, y = 1;
// int ln = 1;
// int m;

// bool dead() {
//     if (st.find({ x,y }) != st.end()) {
//         return true;
//     }
//     return false;
// }

// bool food(pair<int, int>pa) {
//     if (pa.first == x && pa.second == y && fix < m) {

//         st.insert(pa);
//         dq.push_back(pa);
//         ln++;
//         fix++;
//         return true;
//     }
//     return false;
// }
// void increSnk() {

//     st.insert({ x,y });
//     dq.push_back({ x,y });
// }

// int main() {
//     int n, k;
//     cin >> n >> k >> m;

//     string s;
//     cin >> s;

//     bool f = true;

//     vector<pair<int, int>>fd(m);
//     for (int i = 0;i < m;i++) {
//         cin >> fd[i].first >> fd[i].second;
//     }

//     st.insert({ 1,1 });
//     dq.push_back({ 1,1 });

//     for (int i = 0;i < k;i++) {
//         if (s[i] == 'R') {
//             if (y + 1 > n)y = 1;
//             else {
//                 y++;
//             }
//         }
//         else if (s[i] == 'L') {
//             if (y - 1 < 1)y = n;
//             else {
//                 y--;
//             }
//         }
//         else if (s[i] == 'U') {
//             if (x - 1 < 1)x = n;
//             else {
//                 x--;
//             }
//         }
//         else if (s[i] == 'D') {
//             if (x + 1 > n)x = 1;
//             else {
//                 x++;
//             }
//         }
//         bool eat = (fix < m && fd[fix].first == x && fd[fix].second == y);

//         if (!eat) {

//             st.erase(dq.front());
//             dq.pop_front();

//             if (dead()) {
//                 cout << "DEAD";
//                 f = false;
//                 break;
//             }
//             else {
//                 increSnk();
//             }
//         }
//         else {
//             food(fd[fix]);
//         }


//     }

//     if (f) {
//         cout << "ALIVE" << " " << ln;
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 1)cout << a << endl;
        else if (c == 2)cout << b << endl;
        else {
            cout<<(a&b)<<endl;
        }

        
    }
}
