#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W, N;
    cin >> H >> W >> N;

    vector<int> h(N), w(N);
    map<int, vector<int>> match_h, match_w;
    
    for (int i = 0; i < N; i++) {
        cin >> h[i] >> w[i];
        match_h[h[i]].push_back(i);
        match_w[w[i]].push_back(i);
    }

    vector<pair<int, int>> ans(N);
    vector<bool> removed(N, false);
    
    int cur_H = H, cur_W = W;
    int cur_X = 1, cur_Y = 1;

    for (int k = 0; k < N; k++) {
        while (!match_h[cur_H].empty() && removed[match_h[cur_H].back()]) {
            match_h[cur_H].pop_back();
        }
        
        if (!match_h[cur_H].empty()) {
            int idx = match_h[cur_H].back();
            ans[idx] = {cur_X, cur_Y};
            cur_Y += w[idx];
            cur_W -= w[idx];
            removed[idx] = true;
            match_h[cur_H].pop_back();
            continue;
        }

        while (!match_w[cur_W].empty() && removed[match_w[cur_W].back()]) {
            match_w[cur_W].pop_back();
        }

        if (!match_w[cur_W].empty()) {
            int idx = match_w[cur_W].back();
            ans[idx] = {cur_X, cur_Y};
            cur_X += h[idx];
            cur_H -= h[idx];
            removed[idx] = true;
            match_w[cur_W].pop_back();
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    return 0;
}