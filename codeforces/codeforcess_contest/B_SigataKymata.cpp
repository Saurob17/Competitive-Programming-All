// #include <bits/stdc++.h>
// using namespace std;

// struct Extremes {
//     int val, idx;
// };
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t; if(!(cin>>t)) return 0;
//     while(t--){
//         int n; cin>>n;
//         vector<int> p(n+1);
//         for(int i=1;i<=n;i++) cin>>p[i];
//         string x; cin>>x;
//         x = " "+x; // 1-based

//         vector<int> ones;
//         for(int i=1;i<=n;i++) if(x[i]=='1') ones.push_back(i);
//         if(ones.empty()){ cout<<0<<'\n'; continue; }

//         // Precompute prefix/suffix min/max values and their indices
//         const int INF = 1e9+7;
//         vector<int> preMinVal(n+1, INF), preMinIdx(n+1, -1), preMaxVal(n+1, -INF), preMaxIdx(n+1, -1);
//         for(int i=1;i<=n;i++){
//             if(preMinVal[i-1] <= p[i]){ preMinVal[i] = preMinVal[i-1]; preMinIdx[i] = preMinIdx[i-1]; }
//             else { preMinVal[i] = p[i]; preMinIdx[i] = i; }
//             if(preMaxVal[i-1] >= p[i]){ preMaxVal[i] = preMaxVal[i-1]; preMaxIdx[i] = preMaxIdx[i-1]; }
//             else { preMaxVal[i] = p[i]; preMaxIdx[i] = i; }
//         }
//         vector<int> sufMinVal(n+2, INF), sufMinIdx(n+2, -1), sufMaxVal(n+2, -INF), sufMaxIdx(n+2, -1);
//         for(int i=n;i>=1;i--){
//             if(sufMinVal[i+1] <= p[i]){ sufMinVal[i] = sufMinVal[i+1]; sufMinIdx[i] = sufMinIdx[i+1]; }
//             else { sufMinVal[i] = p[i]; sufMinIdx[i] = i; }
//             if(sufMaxVal[i+1] >= p[i]){ sufMaxVal[i] = sufMaxVal[i+1]; sufMaxIdx[i] = sufMaxIdx[i+1]; }
//             else { sufMaxVal[i] = p[i]; sufMaxIdx[i] = i; }
//         }

//         auto can_mark_with = [&](int i, int L, int R){
//             if(L== -1 || R== -1) return false;
//             if(!(L < i && i < R)) return false;
//             int lo = min(p[L], p[R]);
//             int hi = max(p[L], p[R]);
//             return lo < p[i] && p[i] < hi;
//         };

//         auto find_pair_for = [&](int i)->pair<int,int>{
//             // Try left smaller, right greater
//             int Ls = (preMinVal[i-1] < p[i]) ? preMinIdx[i-1] : -1;
//             int Lg = (preMaxVal[i-1] > p[i]) ? preMaxIdx[i-1] : -1;
//             int Rs = (sufMinVal[i+1] < p[i]) ? sufMinIdx[i+1] : -1;
//             int Rg = (sufMaxVal[i+1] > p[i]) ? sufMaxIdx[i+1] : -1;
//             if(Ls != -1 && Rg != -1 && can_mark_with(i, Ls, Rg)) return {Ls, Rg};
//             if(Lg != -1 && Rs != -1 && can_mark_with(i, Lg, Rs)) return {Lg, Rs};
//             // Try alternate: choose any L before and any R after, ensure bounds
//             if(Ls != -1){
//                 // need R with value > p[i]
//                 if(Rg != -1) return {Ls, Rg};
//             }
//             if(Lg != -1){
//                 if(Rs != -1) return {Lg, Rs};
//             }
//             return {-1,-1};
//         };

//         vector<pair<int,int>> ops;
//         auto add_op = [&](int L,int R){ if(L>R) swap(L,R); if(L!=R) ops.push_back({L,R}); };

//         int l = ones.front();
//         int r = ones.back();
//         int mnV = INF, mxV = -INF;
//         for(int idx: ones){ mnV = min(mnV, p[idx]); mxV = max(mxV, p[idx]); }

//         // Try a global covering op
//         bool haveGlobal=false; int gL=-1, gR=-1;
//         // Variant A: left before l with smaller than mn, right after r with greater than mx
//         if(preMinVal[l-1] < mnV && sufMaxVal[r+1] > mxV){
//             gL = preMinIdx[l-1]; gR = sufMaxIdx[r+1]; haveGlobal = true;
//         } else if(preMaxVal[l-1] > mxV && sufMinVal[r+1] < mnV){
//             gL = preMaxIdx[l-1]; gR = sufMinIdx[r+1]; haveGlobal = true;
//         }
//         vector<char> covered(n+1, 0);
//         if(haveGlobal){
//             // Apply conceptual global coverage
//             int lo = min(p[gL], p[gR]);
//             int hi = max(p[gL], p[gR]);
//             for(int idx: ones){ if(gL < idx && idx < gR && lo < p[idx] && p[idx] < hi) covered[idx]=1; }
//             add_op(gL,gR);
//         }

//         // Cover remaining ones individually
//         for(int idx: ones){
//             if(covered[idx]) continue;
//             auto pr = find_pair_for(idx);
//             if(pr.first == -1){
//                 // If no global op, we may try to create another broad op using neighbors around idx when possible
//                 // but keep within 5 ops: fail if cannot mark
//                 ops.clear(); // clear to indicate failure exceeding limit
//                 break;
//             }
//             add_op(pr.first, pr.second);
//             covered[idx]=1;
//             if((int)ops.size() > 5) break;
//         }

//         bool ok = true;
//         if(ops.size() == 0){
//             // Either no ops needed (shouldn't happen since ones non-empty) or failure path
//             // Re-evaluate: can we mark each individually within 5 directly?
//             ops.clear();
//             for(int idx: ones){
//                 auto pr = find_pair_for(idx);
//                 if(pr.first == -1){ ok=false; break; }
//                 add_op(pr.first, pr.second);
//                 if((int)ops.size() > 5){ ok=false; break; }
//             }
//         }
//         if(ok && (int)ops.size() <= 5){
//             cout << ops.size() << '\n';
//             for(auto [L,R]: ops) cout << L << ' ' << R << '\n';
//         }else{
//             cout << -1 << '\n';
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        string s;
        cin >> s;
        int minVal = INT_MAX;
        vector<pair<int, int>> preMin,temp;
        preMin.push_back({a[0], 0});


        for (int i = 1; i < n; i++)
        {
            if (a[i] < minVal)
            {
                minVal = a[i];
                preMin.push_back({a[i], i});
            }
            else
            {
                preMin.push_back(preMin[i - 1]);
            }
        }



    }
}