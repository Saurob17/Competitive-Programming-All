#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<string> grid;
vector<vector<int>> vis;

vector<int> row_add, col_add;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


// DFS for one component
void dfs(int x,int y,int &sz,int &rmin,int &rmax,int &cmin,int &cmax)
{
    vis[x][y]=1;
    sz++;

    rmin=min(rmin,x);
    rmax=max(rmax,x);
    cmin=min(cmin,y);
    cmax=max(cmax,y);

    for(int d=0;d<4;d++)
    {
        int nx=x+dx[d];
        int ny=y+dy[d];

        if(nx>=0 && ny>=0 && nx<n && ny<m)
        {
            if(!vis[nx][ny] && grid[nx][ny]=='#')
                dfs(nx,ny,sz,rmin,rmax,cmin,cmax);
        }
    }
}


// find all components
void find_components()
{
    vis.assign(n, vector<int>(m,0));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='#' && !vis[i][j])
            {
                int sz=0;
                int rmin=i,rmax=i;
                int cmin=j,cmax=j;

                dfs(i,j,sz,rmin,rmax,cmin,cmax);

                // update row contribution range
                int L=max(0,rmin-1);
                int R=min(n-1,rmax);

                row_add[L]+=sz;
                row_add[R+2]-=sz;

                // update col contribution range
                int Lc=max(0,cmin-1);
                int Rc=min(m-1,cmax+1);

                col_add[Lc]+=sz;
                col_add[Rc+1]-=sz;
            }
        }
    }
}


// compute best row answer
int calc_rows()
{
    for(int i=1;i<n;i++)
        row_add[i]+=row_add[i-1];

    int best=0;

    for(int r=0;r<n;r++)
    {
        int dots=0;
        for(int c=0;c<m;c++)
            if(grid[r][c]=='.') dots++;

        best=max(best, dots + row_add[r]);
    }

    return best;
}


// compute best column answer
int calc_cols()
{
    for(int i=1;i<m;i++)
        col_add[i]+=col_add[i-1];

    int best=0;

    for(int c=0;c<m;c++)
    {
        int dots=0;
        for(int r=0;r<n;r++)
            if(grid[r][c]=='.') dots++;

        best=max(best, dots + col_add[c]);
    }

    return best;
}


void solve()
{
    cin>>n>>m;

    grid.resize(n);
    for(int i=0;i<n;i++)
        cin>>grid[i];

    row_add.assign(n+5,0);
    col_add.assign(m+5,0);

    find_components();

    int ans=0;

    ans=max(ans, calc_rows());
    ans=max(ans, calc_cols());

    cout<<ans<<"\n";
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--)
        solve();
}