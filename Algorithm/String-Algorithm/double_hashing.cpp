// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// const ll MOD1 = 1000000007;
// const ll MOD2 = 1000000009;
// const ll P = 31;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     string s, good;
//     int k;
//     cin >> s >> good >> k;

//     int n = s.size();

//     // Prefix sum of bad letters
//     vector<int> bad(n+1, 0);
//     for (int i = 0; i < n; i++) {
//         int idx = s[i] - 'a';
//         if (good[idx] == '0') bad[i+1] = 1;
//     }
//     for (int i = 1; i <= n; i++) bad[i] += bad[i-1];

//     // Precompute powers
//     vector<ll> pow1(n+1, 1), pow2(n+1, 1);
//     for (int i = 1; i <= n; i++) {
//         pow1[i] = (pow1[i-1] * P) % MOD1;
//         pow2[i] = (pow2[i-1] * P) % MOD2;
//     }

//     // Prefix hashes
//     vector<ll> h1(n+1, 0), h2(n+1, 0);
//     for (int i = 0; i < n; i++) {
//         h1[i+1] = (h1[i] * P + (s[i] - 'a' + 1)) % MOD1;
//         h2[i+1] = (h2[i] * P + (s[i] - 'a' + 1)) % MOD2;
//     }

//     auto getHash = [&](int l, int r) -> pair<ll,ll> {
//         ll x1 = (h1[r] - h1[l] * pow1[r-l] % MOD1 + MOD1) % MOD1;
//         ll x2 = (h2[r] - h2[l] * pow2[r-l] % MOD2 + MOD2) % MOD2;
//         return {x1, x2};
//     };

//     // Store distinct good substrings using pair hash
//     set<pair<ll,ll>> st;
//     for (int l = 0; l < n; l++) {
//         for (int r = l+1; r <= n; r++) {
//             int bad_count = bad[r] - bad[l];
//             if (bad_count <= k) {
//                 st.insert(getHash(l, r));
//             }
//         }
//     }

//     cout << st.size() << "\n";
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

// দুইটা বড় prime modulus
const long long mod1 = 1000000007;
const long long mod2 = 1000000009;
const long long base = 131;   // সাধারণত prime base নেওয়া হয়
// maximum size (string length পর্যন্ত)
const int N = 1000005;
long long hash1[N], hash2[N];       // prefix hash
long long pow1[N], pow2[N];         // power array
// Power precompute (base^i % mod)
void precompute(int n) {
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow1[i] = (pow1[i-1] * base) % mod1;
        pow2[i] = (pow2[i-1] * base) % mod2;
    }
}
// Hash build function
void buildHash(string &s) {
    int n = s.size();
    hash1[0] = hash2[0] = 0;
    for (int i = 1; i <= n; i++) {
        hash1[i] = (hash1[i-1] * base + s[i-1]) % mod1;
        hash2[i] = (hash2[i-1] * base + s[i-1]) % mod2;
    }
}
// substring hash পাওয়ার function
pair<long long,long long> getHash(int l, int r) {
    // s[l..r], 1-indexed
    long long x1 = (hash1[r] - (hash1[l-1] * pow1[r-l+1]) % mod1 + mod1) % mod1;
    long long x2 = (hash2[r] - (hash2[l-1] * pow2[r-l+1]) % mod2 + mod2) % mod2;
    return {x1, x2};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    // Precompute power
    precompute(n);

    // Build hash
    buildHash(s);

    // Example: substring compare
    // compare s[l1..r1] with s[l2..r2]
    int l1 = 1, r1 = 3;   // substring s[1..3]
    int l2 = 4, r2 = 6;   // substring s[4..6]

    auto h1 = getHash(l1, r1);
    auto h2 = getHash(l2, r2);

    if (h1 == h2) cout << "Substrings are equal\n";
    else cout << "Not equal\n";

    return 0;
}  
/*
const long long mod1=1e9+7,mod2=1e9+9,base=131;
long long h1[1000005],h2[1000005],p1[1000005],p2[1000005];
void precompute(int n){p1[0]=p2[0]=1;for(int i=1;i<=n;i++)p1[i]=p1[i-1]*base%mod1,p2[i]=p2[i-1]*base%mod2;}
void buildHash(string &s){int n=s.size();for(int i=1;i<=n;i++)h1[i]=(h1[i-1]*base+s[i-1])%mod1,h2[i]=(h2[i-1]*base+s[i-1])%mod2;}
pair<long long,long long> getHash(int l,int r){return {(h1[r]-(h1[l-1]*p1[r-l+1])%mod1+mod1)%mod1,(h2[r]-(h2[l-1]*p2[r-l+1])%mod2+mod2)%mod2};}
*/
/*
const int N=1e5+5;
int n,a[N],st[N][20],log2n[N];

void build(){
    for(int i=0;i<n;i++) st[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=0;i+(1<<j)-1<n;i++)
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){
    int k=log2n[r-l+1];
    return min(st[l][k],st[r-(1<<k)+1][k]);
    }

    // ios::sync_with_stdio(0);cin.tie(0);
    // cin>>n;for(int i=0;i<n;i++) cin>>a[i];
    // log2n[1]=0;for(int i=2;i<=n;i++) log2n[i]=log2n[i/2]+1;
    // build();
    // int q;cin>>q;while(q--){int l,r;cin>>l>>r;cout<<query(l,r)<<"\n";}
*/
//int bs(vector<int>&a,int x){int l=0,r=a.size()-1;while(l<=r){int m=l+(r-l)/2;if(a[m]==x)return m;else if(a[m]<x)l=m+1;else r=m-1;}return -1;}
/*
vector<string> generateGray(int n){
    if(n==0) return {"0"};
    if(n==1) return {"0","1"};
    vector<string> rec=generateGray(n-1),ans;
    for(auto &s: rec) ans.push_back("0"+s);
    for(int i=rec.size()-1;i>=0;i--) ans.push_back("1"+rec[i]);
    return ans;
}*/
/*
const int N=1e5+5; vector<int> g[N]; bool vis[N];
void dfs(int u){vis[u]=1;cout<<u<<" ";for(int v:g[u]) if(!vis[v]) dfs(v);}
int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m;cin>>n>>m;for(int i=0;i<m;i++){int u,v;cin>>u>>v;g[u].push_back(v);g[v].push_back(u);} dfs(1);}

const int N=1e5+5; vector<int> g[N]; bool vis[N];
void bfs(int s){queue<int> q;q.push(s);vis[s]=1;while(!q.empty()){int u=q.front();q.pop();cout<<u<<" ";for(int v:g[u]) if(!vis[v]){vis[v]=1;q.push(v);}}}
int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m;cin>>n>>m;for(int i=0;i<m;i++){int u,v;cin>>u>>v;g[u].push_back(v);g[v].push_back(u);} bfs(1);}
*/
//vector<int> buildLPS(string &s){int n=s.size();vector<int> lps(n,0);for(int i=1,len=0;i<n;)if(s[i]==s[len])lps[i++]=++len;else if(len)len=lps[len-1];else lps[i++]=0;return lps;}
//long long binpow(long long a, long long b, long long m){long long r=1;a%=m;while(b){if(b&1)r=r*a%m;a=a*a%m;b>>=1;}return r;}
//long long ceilDiv(long long a,long long b){return (a+b-1)/b;}
//long long arithSum(long long a,long long d,long long n){return n*(2*a+(n-1)*d)/2;}
//long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
//long long lcm(long long a,long long b){return a/gcd(a,b)*b;}
/*const int N=1e5+5; vector<int> g[N]; int dist[N];
pair<int,int> bfs(int s,int n){fill(dist,dist+n+1,-1);queue<int> q;q.push(s);dist[s]=0;int far=s;while(q.size()){int u=q.front();q.pop();for(int v:g[u]) if(dist[v]==-1) dist[v]=dist[u]+1,q.push(v),far=(dist[v]>dist[far]?v:far);} return {far,dist[far]};}
*/
//vector<int> divisors(int n){vector<int>v;for(int i=1;i*i<=n;i++)if(n%i==0)v.push_back(i),i!=n/i?v.push_back(n/i):0;sort(v.begin(),v.end());return v;}
//const int N = 1e6+5;vector<bool> isPrime(N,true);vector<bool> isPrime(N,true); void sieve(int n){isPrime[0]=isPrime[1]=0;for(int i=2;i*i<=n;i++)if(isPrime[i])for(int j=i*i;j<=n;j+=i)isPrime[j]=0;}
//bool isPrime(long long n){if(n<2)return 0;for(long long i=2;i*i<=n;i++)if(n%i==0)return 0;return 1;}



