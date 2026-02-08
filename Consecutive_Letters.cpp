#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        string S;
        cin >> S;
        int n = S.size();

        int Q;
        cin >> Q;

        set<pair<int,int>> seg;

        // build initial segments
        for(int i = 0; i < n; ){
            int j = i;
            while(j < n && S[j] == S[i]) j++;
            seg.insert({i, j-1});
            i = j;
        }

        cout << "Case " << tc << ":\n";

        while(Q--){
            int type, i;
            cin >> type >> i;

            auto it = seg.upper_bound({i, INT_MAX});
            --it;
            int l = it->first;
            int r = it->second;

            if(type == 1){
                cout << (r - l + 1) << "\n";
            }
            else{
                seg.erase(it);

                if(l <= i-1) seg.insert({l, i-1});
                if(i+1 <= r) seg.insert({i+1, r});

                S[i] = '#';
            }
        }
    }

    return 0;
}
