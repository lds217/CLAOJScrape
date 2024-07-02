#include <bits/stdc++.h>
using namespace std;

int a[2001][2001],n,m,k;
int dp[2001][2001];
int moveX[]={0,0,1,-1};
int moveY[]={1,-1,0,0};
bool visited[2001][2001];


void bfs(int sx,int sy)
{
   queue<pair<int,int> > q;
    q.push({sx,sy});
    visited[sx][sy]=1;
    while(!q.empty())
    {
        int x=q.front().first;
         int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int dx=x+moveX[i];
            int dy=y+moveY[i];
            if(dx<1||dy<1||dx>m||dy>n)
                continue;
            if(dp[dx][dy]-dp[dx][dy-k]-dp[dx-k][dy]+dp[dx-k][dy-k]==0&&dy-k>=0&&dx-k>=0&&visited[dx][dy]==0)
            {
                q.push({dx,dy});
                visited[dx][dy]=1;
            }
        }
    }
    
}

int main()
{
     freopen("THAMDO.INP","r",stdin);
    freopen("THAMDO.OUT","w",stdout);
cin>>m>>n>>k;
  
    for (int x = 1; x <= m; x++)
    {
            for(int y=1; y <= n; y++)
            {
                cin>>a[x][y];
                dp[x][y]=a[x][y]+ dp[x-1][y]+dp[x][y-1]-dp[x-1][y-1];
            }
    }
    int res=0;
  	for (int x = 1; x <= m; x++)
            for(int y=1; y <= n; y++)
            {
                if(dp[x][y]-dp[x][y-k]-dp[x-k][y]+dp[x-k][y-k]==0&&y-k>=0&&x-k>=0&&visited[x][y]==0)
                {
                    bfs(x,y);
                    res++;
              //      cout<<x<<' '<<y<<endl;
                }
			}
    cout<<res;
    
}
