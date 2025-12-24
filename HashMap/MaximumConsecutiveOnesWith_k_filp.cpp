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
vector<string> generateGray(int n){ return n==0?vector<string>{"0"}:n==1?vector<string>{"0","1"}:([](vector<string> r){ vector<string>a; for(auto &s:r)a.push_back("0"+s); for(int i=r.size()-1;i>=0;i--) a.push_back("1"+r[i]); return a; })(generateGray(n-1)); }
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
//vector<int> divisors(int n){vector<int>v;for(int i=1;i*i<=n;i++){if(n%i==0){v.push_back(i); if(i!=n/i) v.push_back(n/i);}} sort(v.begin(),v.end()); return v;}
//const int N = 1e6+5;vector<bool> isPrime(N,true);vector<bool> isPrime(N,true); void sieve(int n){isPrime[0]=isPrime[1]=0;for(int i=2;i*i<=n;i++)if(isPrime[i])for(int j=i*i;j<=n;j+=i)isPrime[j]=0;}
//bool isPrime(long long n){if(n<2)return 0;for(long long i=2;i*i<=n;i++)if(n%i==0)return 0;return 1;}
//vector<vector<int>> multiply(vector<vector<int>>&A,vector<vector<int>>&B){int n=A.size(),m=A[0].size(),p=B[0].size();vector<vector<int>>C(n,vector<int>(p,0));for(int i=0;i<n;i++)for(int j=0;j<p;j++)for(int k=0;k<m;k++)C[i][j]+=A[i][k]*B[k][j];return C;}
//long long fib(int n){long long a=0,b=1;while(n--)swap(a+=b,b);return a;}
//vector<bool> sieve(int n){vector<bool>p(n+1,1);p[0]=p[1]=0;for(int i=2;i*i<=n;i++)if(p[i])for(int j=i*i;j<=n;j+=i)p[j]=0;return p;}
//vector<long long> factors(long long n){vector<long long>f;for(long long i=2;i*i<=n;i++)while(n%i==0)f.push_back(i),n/=i;if(n>1)f.push_back(n);return f;}
//s.size()/s.length(), s.empty(), s[i]/s.at(i), s.substr(pos,len), s.find("x")/s.rfind("x"), s.find_first_of("x")/s.find_last_of("x"), s.append("text")/s+="text", s.insert(pos,"text"), s.erase(pos,len), s.replace(pos,len,"new"), s.clear(), s.compare(t), reverse(s.begin(),s.end()), sort(s.begin(),s.end()), stoi(s)/stol(s)/stoll(s), stof(s)/stod(s), to_string(x), isalpha(c)/isdigit(c)/islower(c)/isupper(c), tolower(c)/toupper(c), stringstream ss(s); ss>>word, s.resize(new_size)
//int lb = lower_bound(v.begin(),v.end(),key)-v.begin(), ub = upper_bound(v.begin(),v.end(),key)-v.begin();lower_bound(v.begin(),v.end(),key)
//mp[key]=val, mp.insert({key,val}), mp.emplace(key,val), mp.at(key), mp.find(key), mp.count(key), mp.erase(key), mp.clear(), mp.size(), mp.empty(), for(auto&p:mp), mp.lower_bound(key), mp.upper_bound(key), mp.swap(other), mp.merge(other)
//s.insert(x), s.emplace(x), s.find(x), s.count(x), s.erase(x), s.erase(s.find(x)), s.clear(), s.size(), s.empty(), for(auto &x:s), s.lower_bound(x), s.upper_bound(x), s.swap(other), s.merge(other), for(auto it=s.rbegin();it!=s.rend();++it)
//priority_queue<int, vector<int>, greater<int>> pq_min; // min-heap priority_queue<int> pq;    // max-heap  priority_queue<int> pq;    
// void propagateBlack(int start, vector<vector<int>> &g, vector<bool> &v){queue<int> q; if(!v[start]) q.push(v[start]=start); while(!q.empty()){int u=q.front();q.pop(); for(int x:g[u]) if(!v[x]) q.push(v[x]=1);}}
// void processQueries(int N, vector<vector<int>> &g, vector<pair<int,int>> &Q){vector<bool> v(N+1,0); for(auto &q:Q) q.first==1?propagateBlack(q.second,g,v):cout<<(v[q.second]?"Yes":"No")<<"\n";}
// vector<vector<int>> revGraph(N+1); for(int i=0,u,v;i<M;i++){cin>>u>>v; revGraph[v].push_back(u);}
//int coinWays(int N,int sum,vector<int>&c){vector<int>dp(sum+1,0);dp[0]=1;for(int i=0;i<N;i++)for(int j=c[i];j<=sum;j++)dp[j]+=dp[j-c[i]];return dp[sum];}
//int knapsack(int N,int W,vector<int>&w,vector<int>&v){vector<int>dp(W+1,0);for(int i=0;i<N;i++)for(int j=W;j>=w[i];j--)dp[j]=max(dp[j],dp[j-w[i]]+v[i]);return dp[W];}
//auto coinCombinations=[&](vector<int>&coins,int target){vector<vector<vector<int>>>dp(target+1);dp[0].push_back({});for(int c:coins)for(int t=c;t<=target;t++)for(auto comb:dp[t-c]){comb.push_back(c);dp[t].push_back(comb);}vector<vector<pair<int,int>>>res;for(auto &comb:dp[target]){map<int,int>freq;for(int x:comb)freq[x]++;vector<pair<int,int>>v;for(auto &[coin,count]:freq)v.push_back({coin,count});res.push_back(v);}return res;};
//_builtin_ffs(x)	Returns 1-based position of first set bit from LSB
//_builtin_ffsll(x)//check ith bit bool isSet = (x >> i) & 1;//i-th bit toggle x ^= (1 << i);
//auto LsubWotNonRepCHar = [](string s){ unordered_map<char,int> mp; int ans=0,j=0; for(int i=0;i<s.size();i++){ mp[s[i]]++; while(mp[s[i]]>1) mp[s[j++]]--; for(int k=1;k<=i-j+1;k++) ans+=sumOfOneTOn(k); } return ans; };
//sublime  {"cmd":["g++ -std=c++14 $file_name -o $file_base_name && timeout 4s ./$file_base_name<inputf.in>outputf.in"],"selector":"source.c","shell":true,"working_dir":"$file_path"}

 #include <bits/stdc++.h>
    using namespace std;
    int main(){
        int n,k;cin>>n>>k;
       cout<<n+k;
    }

