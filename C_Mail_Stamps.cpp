#include <bits/stdc++.h>
using namespace std;

vector<bool> vis(1e5 + 7);
int last = 0;
int max_dist = -1;
vector<int> chain;

// দূরতম নোড (End point) বের করার জন্য DFS
void dfs(int node, int d, vector<vector<int>> &adj) {
    vis[node] = true;
    if (d > max_dist) {
        max_dist = d;
        last = node; // সবচেয়ে দূরে যে নোডটি পাওয়া যাবে সেটাই শেষ প্রান্ত
    }
    for (auto child : adj[node]) {
        if (!vis[child]) {
            dfs(child, d + 1, adj);
        }
    }
}

// চেইন প্রিন্ট করার জন্য DFS (Simple DFS)
void dfs1(int node, vector<vector<int>> &adj) {
    vis[node] = true;
    chain.push_back(node);
    for (auto child : adj[node]) {
        if (!vis[child]) {
            dfs1(child, adj);
        }
    }
}

int main() {
    int n;
    if(!(cin >> n)) return 0;
    
    // সাইজ সবসময় vis এর সমান রাখা ভালো
    vector<vector<int>> adj(1e5 + 7); 
    int str = 0;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        str = u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // ১. যেকোনো নোড থেকে সবচেয়ে দূরের নোড (last) খুঁজি
    fill(vis.begin(), vis.end(), false);
    dfs(str, 0, adj);

    // ২. এবার ঐ 'last' নোড থেকে আবার সবচেয়ে লম্বা চেইন খুঁজি
    fill(vis.begin(), vis.end(), false);
    chain.clear();
    dfs1(last, adj);

    for (auto it : chain) {
        cout << it << " ";
    }
    return 0;
}