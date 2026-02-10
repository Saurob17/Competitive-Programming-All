
/* ios::sync_with_stdio(false);
    cin.tie(nullptr);
*/

//void primeFactors(int n){for(;n%2==0;cout<<2<<" ",n/=2);for(int i=3;i*i<=n;i+=2)for(;n%i==0;cout<<i<<" ",n/=i);if(n>2)cout<<n;}


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
//binary search
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
//const int N=1e8+1;bool isPrime[N];void sieve(){fill(isPrime,isPrime+N,true);isPrime[0]=isPrime[1]=false;for(long long i=2;i*i<N;i++)if(isPrime[i])for(long long j=i*i;j<N;j+=i)isPrime[j]=false;}
//sum of divisor

/*
#include <bits/stdc++.h>
using namespace std;
using int128 = __int128_t;
vector<int> primes; const int MAXP=1e6; bool is_prime[MAXP+1]; // sieve up to 1e6

void sieve(){fill(is_prime,is_prime+MAXP+1,true);is_prime[0]=is_prime[1]=false;for(int i=2;i*i<=MAXP;i++)if(is_prime[i])for(int j=i*i;j<=MAXP;j+=i)is_prime[j]=false;for(int i=2;i<=MAXP;i++)if(is_prime[i])primes.push_back(i);}

int128 sumDiv(int128 n){int128 ans=1,temp=n; for(int p:primes){if(1LL*p*p>n)break;if(n%p==0){int128 term=1,pp=1;while(n%p==0){n/=p;pp*=p;term+=pp;}ans*=term;}} if(n>1)ans*=(n+1); return ans-temp;}

void print(int128 x){if(x==0){cout<<0<<"\n";return;}string s;while(x>0){s.push_back('0'+x%10);x/=10;}reverse(s.begin(),s.end());cout<<s<<"\n";}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);sieve();int T;cin>>T;while(T--){long long n;cin>>n;if(n==1){cout<<0<<"\n";continue;}print(sumDiv(n));}}
*/
/*
#include <bits/stdc++.h>
using namespace std;
const int N=1000,W=1000; int n,wt[N],val[N]; // items & weights/values
int knap01(int maxW){vector<int> dp(maxW+1,0);for(int i=0;i<n;i++)for(int w=maxW;w>=wt[i];w--)dp[w]=max(dp[w],val[i]+dp[w-wt[i]]);return dp[maxW];}
int knapUnb(int maxW){vector<int> dp(maxW+1,0);for(int i=0;i<n;i++)for(int w=wt[i];w<=maxW;w++)dp[w]=max(dp[w],val[i]+dp[w-wt[i]]);return dp[maxW];}
bool subsetSum(int target){vector<bool> dp(target+1,false);dp[0]=true;for(int i=0;i<n;i++)for(int w=target;w>=wt[i];w--)dp[w]=dp[w]||dp[w-wt[i]];return dp[target];}
int main(){ios::sync_with_stdio(0);cin.tie(0);
cin>>n;for(int i=0;i<n;i++)cin>>wt[i];for(int i=0;i<n;i++)cin>>val[i];
int maxW,target;cin>>maxW>>target;
cout<<knap01(maxW)<<"\n"<<knapUnb(maxW)<<"\n"<<(subsetSum(target)?"Yes":"No")<<"\n";}
*/
//fibonacchi
// using ll=long long; void mul(ll a[2][2],ll b[2][2]){ll c[2][2];c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];c[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];c[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];a[0][0]=c[0][0];a[0][1]=c[0][1];a[1][0]=c[1][0];a[1][1]=c[1][1];} void power(ll F[2][2],ll n){if(n<=1)return; ll M[2][2]={{1,1},{1,0}}; power(F,n/2); mul(F,F); if(n%2) mul(F,M);} ll fib(ll n){if(n==0) return 0; ll F[2][2]={{1,1},{1,0}}; power(F,n-1); return F[0][0];} int main(){ios::sync_with_stdio(0);cin.tie(0); ll n; cin>>n; cout<<fib(n)<<"\n";}
//cycle
//using namespace std; bool dfs(int u, vector<vector<int>>&a, vector<bool>&v, vector<bool>&p){v[u]=p[u]=true; for(int x:a[u]){if(!v[x]&&dfs(x,a,v,p))return true; else if(p[x])return true;}p[u]=false;return false;} int main(){ios::sync_with_stdio(0);cin.tie(0); int n,m; cin>>n>>m; vector<vector<int>>a(n); for(int i=0;i<m;i++){int u,vv; cin>>u>>vv; a[u].push_back(vv);} vector<bool>v(n,false),p(n,false); for(int i=0;i<n;i++) if(!v[i]&&dfs(i,a,v,p)){cout<<"Cycle Found\n";return 0;} cout<<"No Cycle\n";}
//strongly 
//using namespace std; bool dfs(int u, vector<vector<int>>&a, vector<bool>&v, vector<bool>&p){v[u]=p[u]=true; for(int x:a[u]) if(!v[x]&&dfs(x,a,v,p)) return true; else if(p[x]) return true; p[u]=false; return false;} int main(){ios::sync_with_stdio(0);cin.tie(0); int n,m; cin>>n>>m; vector<vector<int>>a(n); for(int i=0;i<m;i++){int u,vv; cin>>u>>vv; a[u].push_back(vv);} vector<bool>v(n,false),p(n,false); for(int i=0;i<n;i++) if(!v[i]&&dfs(i,a,v,p)){cout<<"Cycle Found\n";return 0;} cout<<"No Cycle\n";}
//dsu
//using namespace std; vector<int>par,rnk; int find(int u){return par[u]==u?u:par[u]=find(par[u]);} bool unite(int u,int v){u=find(u);v=find(v); if(u==v)return true; if(rnk[u]<rnk[v])swap(u,v); par[v]=u; if(rnk[u]==rnk[v])rnk[u]++; return false;} int main(){ios::sync_with_stdio(0);cin.tie(0); int n,m; cin>>n>>m; par.resize(n); rnk.resize(n,0); iota(par.begin(),par.end(),0); bool cycle=false; for(int i=0;i<m;i++){int u,vv; cin>>u>>vv; if(unite(u,vv)) cycle=true;} cout<<(cycle?"Cycle Found\n":"No Cycle\n");}
/*
const int MOD=1e9+7,N=1e6;
long long fact[N+1],invfact[N+1];

// fast exponentiation
long long modpow(long long a,long long b){long long r=1;while(b){if(b&1) r=r*a%MOD;a=a*a%MOD;b>>=1;}return r;}

// precompute factorials and inverse factorials
void precompute(){fact[0]=1;for(int i=1;i<=N;i++) fact[i]=fact[i-1]*i%MOD;invfact[N]=modpow(fact[N],MOD-2);for(int i=N-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%MOD;}

// nCr modulo MOD
long long nCr_mod(int n,int r){return r>n?0:fact[n]*invfact[r]%MOD*invfact[n-r]%MOD;}

// nPr modulo MOD
long long nPr_mod(int n,int r){return r>n?0:fact[n]*invfact[n-r]%MOD;}

*/
//grid
//int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1}; void dfs(int i,int j,int n,int m,vector<vector<int>>&g,vector<vector<bool>>&v){v[i][j]=1; for(int k=0;k<4;k++){int ni=i+dx[k],nj=j+dy[k]; if(ni>=0&&ni<n&&nj>=0&&nj<m&&!v[ni][nj]&&g[ni][nj]) dfs(ni,nj,n,m,g,v);}} int main(){int n,m; cin>>n>>m; vector<vector<int>>g(n,vector<int>(m)); vector<vector<bool>>v(n,vector<bool>(m,0)); for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>g[i][j]; int ans=0; for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(g[i][j]&&!v[i][j]) dfs(i,j,n,m,g,v),ans++; cout<<ans<<"\n";}
//  cout << fixed << setprecision(2) << pi << endl;
//17F59AF105A699103B2EAAF1047AF93A

//c822c1c4acbb59790a39f2f8286e99b1c3f74c71-%00SessionKey%3A8ac0a2aaaa15989ff9f71d393b6d331ac21881664916ed6e5b5a19be31961977%00%00UserScreenName%3Asaurob_noob%00%00UserName%3Asaurob_noob%00%00a%3Afalse%00%00w%3Afalse%00%00csrf_token%3AcDg7xw0OzrLySdCPxgth%2FPXZgz5A0189bFVTvFKuQk8%3D%00%00_TS%3A1784027662%00
//int idx = lower_bound(s.begin(), s.end(), 'b') - s.begin();
//int idx = upper_bound(s.begin(), s.end(), 'b') - s.begin();
//int cnt = upper_bound(s.begin(),s.end(),'b')
 //       - lower_bound(s.begin(),s.end(),'b');
 /*
 int x = stoi(s);        // string to int
long long y = stoll(s);
double d = stod(s);

string t = to_string(123);
s.substr(i,len);                 // get substring
s.find(sub)!=string::npos;       // check exists
s.erase(i,len);                  // delete substring
s.replace(i,len,sub);            // replace substring
s.insert(i,sub);                 // insert substring
string s = "abcdef";                 // মূল string

string a = s.substr(2,3);            // index 2 থেকে 3টা character নিয়ে substring ("cde")
string b = s.substr(3);              // index 3 থেকে শেষ পর্যন্ত substring ("def")

if(s.find("cd") != string::npos)     // "cd" substring আছে কিনা check
    cout<<"Found\n";

int p1 = s.find("c");                // 'c' এর প্রথম occurrence এর index
int p2 = s.rfind("c");               // 'c' এর শেষ occurrence এর index

int cnt=0;                           // substring কয়বার আছে তা গণনার জন্য
for(int pos=0;(pos=s.find("a",pos))!=string::npos;pos++)
    cnt++;                           // overlapping সহ "a" এর সংখ্যা count

s.erase(2,3);                        // index 2 থেকে 3টা character মুছে ফেলে

s.replace(1,2,"XX");                 // index 1 থেকে 2টা character বদলে "XX" বসায়

s.insert(3,"ZZ");                    // index 3 তে "ZZ" ঢুকিয়ে দেয়

if(s.substr(0,3)=="abc")             // প্রথম 3টা character "abc" কিনা check
    cout<<"Match\n";

for(int i=0;i<s.size();i++)          // সব possible substring বের করার জন্য
    for(int len=1;i+len<=s.size();len++)
        cout<<s.substr(i,len)<<"\n"; // index i থেকে len দৈর্ঘ্যের substring print

string pre = s.substr(0,k);          // প্রথম kটা character (prefix)

string suf = s.substr(s.size()-k);   // শেষ kটা character (suffix)

s.erase(0,k);                        // প্রথম kটা character মুছে ফেলে
s.erase(s.size()-k);                 // শেষ kটা character মুছে ফেলে

*/

/* ios::sync_with_stdio(false);
    cin.tie(nullptr);
*/

//void primeFactors(int n){for(;n%2==0;cout<<2<<" ",n/=2);for(int i=3;i*i<=n;i+=2)for(;n%i==0;cout<<i<<" ",n/=i);if(n>2)cout<<n;}


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
//binary search
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
//const int N=1e8+1;bool isPrime[N];void sieve(){fill(isPrime,isPrime+N,true);isPrime[0]=isPrime[1]=false;for(long long i=2;i*i<N;i++)if(isPrime[i])for(long long j=i*i;j<N;j+=i)isPrime[j]=false;}
//sum of divisor

/*
#include <bits/stdc++.h>
using namespace std;
using int128 = __int128_t;
vector<int> primes; const int MAXP=1e6; bool is_prime[MAXP+1]; // sieve up to 1e6

void sieve(){fill(is_prime,is_prime+MAXP+1,true);is_prime[0]=is_prime[1]=false;for(int i=2;i*i<=MAXP;i++)if(is_prime[i])for(int j=i*i;j<=MAXP;j+=i)is_prime[j]=false;for(int i=2;i<=MAXP;i++)if(is_prime[i])primes.push_back(i);}

int128 sumDiv(int128 n){int128 ans=1,temp=n; for(int p:primes){if(1LL*p*p>n)break;if(n%p==0){int128 term=1,pp=1;while(n%p==0){n/=p;pp*=p;term+=pp;}ans*=term;}} if(n>1)ans*=(n+1); return ans-temp;}

void print(int128 x){if(x==0){cout<<0<<"\n";return;}string s;while(x>0){s.push_back('0'+x%10);x/=10;}reverse(s.begin(),s.end());cout<<s<<"\n";}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);sieve();int T;cin>>T;while(T--){long long n;cin>>n;if(n==1){cout<<0<<"\n";continue;}print(sumDiv(n));}}
*/
/*
#include <bits/stdc++.h>
using namespace std;
const int N=1000,W=1000; int n,wt[N],val[N]; // items & weights/values
int knap01(int maxW){vector<int> dp(maxW+1,0);for(int i=0;i<n;i++)for(int w=maxW;w>=wt[i];w--)dp[w]=max(dp[w],val[i]+dp[w-wt[i]]);return dp[maxW];}
int knapUnb(int maxW){vector<int> dp(maxW+1,0);for(int i=0;i<n;i++)for(int w=wt[i];w<=maxW;w++)dp[w]=max(dp[w],val[i]+dp[w-wt[i]]);return dp[maxW];}
bool subsetSum(int target){vector<bool> dp(target+1,false);dp[0]=true;for(int i=0;i<n;i++)for(int w=target;w>=wt[i];w--)dp[w]=dp[w]||dp[w-wt[i]];return dp[target];}
int main(){ios::sync_with_stdio(0);cin.tie(0);
cin>>n;for(int i=0;i<n;i++)cin>>wt[i];for(int i=0;i<n;i++)cin>>val[i];
int maxW,target;cin>>maxW>>target;
cout<<knap01(maxW)<<"\n"<<knapUnb(maxW)<<"\n"<<(subsetSum(target)?"Yes":"No")<<"\n";}
*/
//fibonacchi
// using ll=long long; void mul(ll a[2][2],ll b[2][2]){ll c[2][2];c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];c[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];c[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];a[0][0]=c[0][0];a[0][1]=c[0][1];a[1][0]=c[1][0];a[1][1]=c[1][1];} void power(ll F[2][2],ll n){if(n<=1)return; ll M[2][2]={{1,1},{1,0}}; power(F,n/2); mul(F,F); if(n%2) mul(F,M);} ll fib(ll n){if(n==0) return 0; ll F[2][2]={{1,1},{1,0}}; power(F,n-1); return F[0][0];} int main(){ios::sync_with_stdio(0);cin.tie(0); ll n; cin>>n; cout<<fib(n)<<"\n";}
//cycle
//using namespace std; bool dfs(int u, vector<vector<int>>&a, vector<bool>&v, vector<bool>&p){v[u]=p[u]=true; for(int x:a[u]){if(!v[x]&&dfs(x,a,v,p))return true; else if(p[x])return true;}p[u]=false;return false;} int main(){ios::sync_with_stdio(0);cin.tie(0); int n,m; cin>>n>>m; vector<vector<int>>a(n); for(int i=0;i<m;i++){int u,vv; cin>>u>>vv; a[u].push_back(vv);} vector<bool>v(n,false),p(n,false); for(int i=0;i<n;i++) if(!v[i]&&dfs(i,a,v,p)){cout<<"Cycle Found\n";return 0;} cout<<"No Cycle\n";}
//strongly 
//using namespace std; bool dfs(int u, vector<vector<int>>&a, vector<bool>&v, vector<bool>&p){v[u]=p[u]=true; for(int x:a[u]) if(!v[x]&&dfs(x,a,v,p)) return true; else if(p[x]) return true; p[u]=false; return false;} int main(){ios::sync_with_stdio(0);cin.tie(0); int n,m; cin>>n>>m; vector<vector<int>>a(n); for(int i=0;i<m;i++){int u,vv; cin>>u>>vv; a[u].push_back(vv);} vector<bool>v(n,false),p(n,false); for(int i=0;i<n;i++) if(!v[i]&&dfs(i,a,v,p)){cout<<"Cycle Found\n";return 0;} cout<<"No Cycle\n";}
//dsu
//using namespace std; vector<int>par,rnk; int find(int u){return par[u]==u?u:par[u]=find(par[u]);} bool unite(int u,int v){u=find(u);v=find(v); if(u==v)return true; if(rnk[u]<rnk[v])swap(u,v); par[v]=u; if(rnk[u]==rnk[v])rnk[u]++; return false;} int main(){ios::sync_with_stdio(0);cin.tie(0); int n,m; cin>>n>>m; par.resize(n); rnk.resize(n,0); iota(par.begin(),par.end(),0); bool cycle=false; for(int i=0;i<m;i++){int u,vv; cin>>u>>vv; if(unite(u,vv)) cycle=true;} cout<<(cycle?"Cycle Found\n":"No Cycle\n");}
/*
const int MOD=1e9+7,N=1e6;
long long fact[N+1],invfact[N+1];

// fast exponentiation
long long modpow(long long a,long long b){long long r=1;while(b){if(b&1) r=r*a%MOD;a=a*a%MOD;b>>=1;}return r;}

// precompute factorials and inverse factorials
void precompute(){fact[0]=1;for(int i=1;i<=N;i++) fact[i]=fact[i-1]*i%MOD;invfact[N]=modpow(fact[N],MOD-2);for(int i=N-1;i>=0;i--) invfact[i]=invfact[i+1]*(i+1)%MOD;}

// nCr modulo MOD
long long nCr_mod(int n,int r){return r>n?0:fact[n]*invfact[r]%MOD*invfact[n-r]%MOD;}

// nPr modulo MOD
long long nPr_mod(int n,int r){return r>n?0:fact[n]*invfact[n-r]%MOD;}

*/
//grid
//int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1}; void dfs(int i,int j,int n,int m,vector<vector<int>>&g,vector<vector<bool>>&v){v[i][j]=1; for(int k=0;k<4;k++){int ni=i+dx[k],nj=j+dy[k]; if(ni>=0&&ni<n&&nj>=0&&nj<m&&!v[ni][nj]&&g[ni][nj]) dfs(ni,nj,n,m,g,v);}} int main(){int n,m; cin>>n>>m; vector<vector<int>>g(n,vector<int>(m)); vector<vector<bool>>v(n,vector<bool>(m,0)); for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>g[i][j]; int ans=0; for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(g[i][j]&&!v[i][j]) dfs(i,j,n,m,g,v),ans++; cout<<ans<<"\n";}
//  cout << fixed << setprecision(2) << pi << endl;
//17F59AF105A699103B2EAAF1047AF93A

//c822c1c4acbb59790a39f2f8286e99b1c3f74c71-%00SessionKey%3A8ac0a2aaaa15989ff9f71d393b6d331ac21881664916ed6e5b5a19be31961977%00%00UserScreenName%3Asaurob_noob%00%00UserName%3Asaurob_noob%00%00a%3Afalse%00%00w%3Afalse%00%00csrf_token%3AcDg7xw0OzrLySdCPxgth%2FPXZgz5A0189bFVTvFKuQk8%3D%00%00_TS%3A1784027662%00
//int idx = lower_bound(s.begin(), s.end(), 'b') - s.begin();
//int idx = upper_bound(s.begin(), s.end(), 'b') - s.begin();
//int cnt = upper_bound(s.begin(),s.end(),'b')
 //       - lower_bound(s.begin(),s.end(),'b');
 /*
 int x = stoi(s);        // string to int
long long y = stoll(s);
double d = stod(s);

string t = to_string(123);
s.substr(i,len);                 // get substring
s.find(sub)!=string::npos;       // check exists
s.erase(i,len);                  // delete substring
s.replace(i,len,sub);            // replace substring
s.insert(i,sub);                 // insert substring
string s = "abcdef";                 // মূল string

string a = s.substr(2,3);            // index 2 থেকে 3টা character নিয়ে substring ("cde")
string b = s.substr(3);              // index 3 থেকে শেষ পর্যন্ত substring ("def")

if(s.find("cd") != string::npos)     // "cd" substring আছে কিনা check
    cout<<"Found\n";

int p1 = s.find("c");                // 'c' এর প্রথম occurrence এর index
int p2 = s.rfind("c");               // 'c' এর শেষ occurrence এর index

int cnt=0;                           // substring কয়বার আছে তা গণনার জন্য
for(int pos=0;(pos=s.find("a",pos))!=string::npos;pos++)
    cnt++;                           // overlapping সহ "a" এর সংখ্যা count

s.erase(2,3);                        // index 2 থেকে 3টা character মুছে ফেলে

s.replace(1,2,"XX");                 // index 1 থেকে 2টা character বদলে "XX" বসায়

s.insert(3,"ZZ");                    // index 3 তে "ZZ" ঢুকিয়ে দেয়

if(s.substr(0,3)=="abc")             // প্রথম 3টা character "abc" কিনা check
    cout<<"Match\n";

for(int i=0;i<s.size();i++)          // সব possible substring বের করার জন্য
    for(int len=1;i+len<=s.size();len++)
        cout<<s.substr(i,len)<<"\n"; // index i থেকে len দৈর্ঘ্যের substring print

string pre = s.substr(0,k);          // প্রথম kটা character (prefix)

string suf = s.substr(s.size()-k);   // শেষ kটা character (suffix)

s.erase(0,k);                        // প্রথম kটা character মুছে ফেলে
s.erase(s.size()-k);                 // শেষ kটা character মুছে ফেলে

*/

#include<bits/stdc++.h>
using namespace std;

int fix = 0;

deque<pair<int, int>>dq;
set<pair<int, int>>st;

int x = 1, y = 1;
int ln = 1;
int m;

bool dead() {
    if (st.find({ x,y }) != st.end()) {
        return true;
    }
    return false;
}

bool food(pair<int, int>pa) {
    if (pa.first == x && pa.second == y && fix<m) {

        st.insert(pa);
        dq.push_back(pa);
        ln++;
        fix++;
        return true;
    }
    return false;
}
void increSnk() {
    st.erase(dq.front());
    dq.pop_front();
    st.insert({ x,y });
    dq.push_back({ x,y });
}

int main() {
    int n, k;
    cin >> n >> k >> m;

    string s;
    cin >> s;

    bool f = true;

    vector<pair<int, int>>fd(m);
    for (int i = 0;i < m;i++) {
        cin >> fd[i].first >> fd[i].second;
    }

    st.insert({ 1,1 });
    dq.push_back({ 1,1 });

    for (int i = 0;i < k;i++) {
        if (s[i] == 'R') {
            if (y + 1 > n)y = 1;
            else {
                y++;
            }
            if (dead()) {
                cout << "DEAD";
                f = false;
                break;
            }
            else if (food(fd[fix])) {
                continue;
            }
            else {
                increSnk();
            }

        }
        else if (s[i] == 'L') {
            if (y - 1 < 1)y = n;
            else {
                y--;
            }
            if (dead()) {
                cout << "DEAD";
                f = false;
                break;
            }
            else if (food(fd[fix])) {
                continue;
            }
            else {
                increSnk();
            }

        }
        else if (s[i] == 'U') {
            if (x - 1 < 1)x = n;
            else {
                x--;
            }
            if (dead()) {
                cout << "DEAD";
                f = false;
                break;
            }
            else if (food(fd[fix])) {
                continue;
            }
            else {
                increSnk();
            }

        }
        else if (s[i] == 'D') {
            if (x + 1 > n)x = 1;
            else {
                x++;
            }
            if (dead()) {
                cout << "DEAD";
                f = false;
                break;
            }
            else if (food(fd[fix])) {
                continue;
            }
            else {
                increSnk();
            }

        }
    }

    if (f) {
        cout << "ALIVE" << " " << ln;
    }

    return 0;
}