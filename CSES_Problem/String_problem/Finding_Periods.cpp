// #include <bits/stdc++.h>
// using namespace std;

// const long long INF = 1e18;

// int main() {
//     int n = 5; // nodes
//     int m = 6; // edges

//     // adjacency list: adj[u] = vector of {v, weight}
//     vector<vector<pair<int,int>>> adj(n+1);

//     // edges {u,v,w} add directly using pair
//     adj[1].push_back({2,2});
//     adj[1].push_back({3,4});
//     adj[2].push_back({1,2});
//     adj[2].push_back({3,1});
//     adj[2].push_back({4,7});
//     adj[3].push_back({1,4});
//     adj[3].push_back({2,1});
//     adj[3].push_back({5,3});
//     adj[4].push_back({2,7});
//     adj[4].push_back({5,1});
//     adj[5].push_back({3,3});
//     adj[5].push_back({4,1});

//     int src = 1;
//     vector<long long> dist(n+1, INF);
//     dist[src] = 0;

//     // Min-heap: {distance, node}
//     priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
//     pq.push({0, src});

//     while(!pq.empty()){
//         auto [d,u] = pq.top(); pq.pop();

//         if(d != dist[u]) continue; // ignore outdated entry

//         for(auto [v,w]: adj[u]){
//             if(dist[v] > dist[u] + w){
//                 dist[v] = dist[u] + w;
//                 pq.push({dist[v], v});
//             }
//         }
//     }

//     // Print shortest distances
//     for(int i=1;i<=n;i++){
//         cout << "Distance from " << src << " to " << i << " = ";
//         if(dist[i] == INF) cout << "INF\n";
//         else cout << dist[i] << "\n";
//     }

//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD1 = 1000000007;
const ll MOD2 = 1000000009;//
const ll BASE = 911382323;

vector<ll> pow1, pow2, h1, h2;

// Precompute powers
void precompute(int n){
    pow1.assign(n+1,1);
    pow2.assign(n+1,1);
    for(int i=1;i<=n;i++){
        pow1[i] = (pow1[i-1]*BASE)%MOD1;
        pow2[i] = (pow2[i-1]*BASE)%MOD2;
    }
}

// Build prefix hash
void buildHash(const string &s){
    int n = s.size();
    h1.assign(n+1,0);
    h2.assign(n+1,0);
    for(int i=0;i<n;i++){
        h1[i+1] = (h1[i]*BASE + s[i]) % MOD1;
        h2[i+1] = (h2[i]*BASE + s[i]) % MOD2;
    }
}

// Get hash of substring [l,r] (1-indexed)
pair<ll,ll> getHash(int l,int r){
    ll x1 = (h1[r] - h1[l-1]*pow1[r-l+1]%MOD1 + MOD1)%MOD1;
    ll x2 = (h2[r] - h2[l-1]*pow2[r-l+1]%MOD2 + MOD2)%MOD2;
    return {x1,x2};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int n = s.size();

    precompute(n);
    buildHash(s);

    vector<int> periods;

    // prefix hash for quick compare
    auto prefixHash = [&](int len){
        return getHash(1,len);
    };

    for(int p=1;p<=n;p++){
        auto pref = prefixHash(p);
        bool ok = true;

        // check all full blocks
        int fullBlocks = n/p;
        for(int b=1;b<fullBlocks;b++){
            if(getHash(b*p+1,(b+1)*p)!=pref){
                ok = false;
                break;
            }
        }
        if(!ok) continue;

        // check last partial block
        int rem = n % p;
        if(rem>0){
            if(getHash(fullBlocks*p+1, n) != getHash(1,rem)){
                ok = false;
            }
        }

        if(ok) periods.push_back(p);
    }

    for(int x: periods) cout << x << " ";
    cout << "\n";
}
