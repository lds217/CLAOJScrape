#include <bits/stdc++.h>
using namespace std;



map<pair<int,int>,int>  M;
int dx[] = {-1, -1, -1, 0, 1, 1,  1,  0};
int dy[] = {-1,  0,  1, 1, 1, 0, -1, -1};

void bfs(int x0,int y0)
{
    queue<pair<int,int>>q;
    
    M[pair<int,int>(x0,y0)] =0;
    q.push(pair<int,int>(x0,y0));
    while(!q.empty())
    {
        pair<int,int> u = q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            pair <int,int> v= pair<int,int>(u.first+dx[i],u.second+dy[i]);
            if(M[v]==-1)
            {
                M[v]=M[u]+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int x0,y0,x1,y1,n;
    cin>>x0>>y0>>x1>>y1;
    cin>>n;
    for(int x=1;x<=n;x++)   {
        int r,a,b;
        cin>>r>>a>>b;
        for(int i = a; i <= b; i++) M[pair<int,int>(r,i)] = -1;
    }
    bfs(x0,y0);
    cout<<M[pair<int,int>(x1,y1)];
}
