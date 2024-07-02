#include <bits/stdc++.h>
using namespace std;

int n,m,p,f,value[200005],path[200005];
vector <int> K[200005];

void bfs(int p)
{
    for(int i=0;i<=n;i++)
        value[i]=1e9;
    queue<int> q;
    q.push(p);
    value[p]=0;
    while(!q.empty())
    {
       int u=q.front();
        q.pop();
        for(int v:K[u])
        {
            if(value[u]+1<value[v])
            {
                value[v]=value[u]+1;
                q.push(v);
                path[v]=u;
            }
        }
    }
     if(value[f]==1e9)
    {
        cout<<-1;
        return;
    }
    cout<<value[f]+1<<endl;
    vector<int> ans;
    int tmp=f;

    ans.push_back(f);
    while(tmp!=p)
    {
        ans.push_back(path[tmp]);
        tmp=path[tmp];
    }
    reverse(ans.begin(),ans.end());
    for(int i:ans)
        cout<<i<<' ';
}

int main()
{
    cin>>n>>m>>p>>f;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        K[u].push_back(v);
        K[v].push_back(u);
    }
    bfs(p);
}
