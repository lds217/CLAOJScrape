#include <bits/stdc++.h>
using namespace std;
int n,m;
vector <int> K[301];
bool fwd[301], back[301];int cnt=0,res=1e9;

void dfs2(int u)
{
    if(cnt>res)
     return;
	if(u==1)
	{
		res=min(res,cnt);
		return;
	}
	for(int v: K[u])
		if(back[v]==0)
		{
			back[v]=1;
			if(fwd[v]==0)
				cnt++;
			dfs2(v);
			back[v]=0;
			if(fwd[v]==0)
				cnt--;
		}
}

void dfs(int u)
{
    if(cnt>=res)
        return;
	if(u==2)
	{
		dfs2(u);
		return ;
	}
	
	for(int v: K[u])
		if(fwd[v]==0)
		{
			cnt++;
			fwd[v]=1;
			dfs(v);
			fwd[v]=0;
			cnt--;
		}
}

int main()
{
	freopen("LITTLE.INP","r",stdin);
	freopen("LITTLE.OUT","w",stdout);
	cin>>n>>m;
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		K[u].push_back(v);
	}
	dfs(1);
	cout<<res;
}
