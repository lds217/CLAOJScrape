#include <bits/stdc++.h>
using namespace std;

int m,n,a[1005][1005],visited[1005][1005];
bool peak[1005][1005];
int moveX[]={1,-1,0,0,1,1,-1,-1};
int moveY[]={0,0,-1,1,-1,1,-1,1};

bool bfs(int sx,int sy)
{
    queue <pair<int,int> > q;
    q.push({sx,sy});
    visited[sx][sy]=1;
    bool ishill=1;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<8;i++)

        {
            int u= x + moveX[i];
            int v = y + moveY[i];
            if (u >= m || u < 0 || v >= n || v < 0)
                continue;
            if(a[u][v]>a[x][y])
            	ishill=0;
           	if(visited[u][v]==0&&a[u][v]==a[x][y])
            {
              visited[u][v]=1;
                q.push({u,v});
            }
        }
	}
	if(ishill==0) return false;
	else return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
     freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);
    cin>>m>>n;
    for(int x=0;x<m;x++)
        for(int y=0;y<n;y++)
            cin>>a[x][y],visited[x][y]=0,peak[x][y]=1;
            int res=0;
    for(int x=0;x<m;x++)
        for(int y=0;y<n;y++)
        {
            if(visited[x][y]==0)
            	if(bfs(x,y))
            		res++;
        }
    cout<<res;


}
