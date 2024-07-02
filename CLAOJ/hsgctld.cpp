#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
#include <iterator>
using namespace std;

int n,m,e,p,b;
int vb[100001],value[100001],visited[100001];
vector<int> K[100001],ans;
stack <int> s;
queue <int> q;
int minn=1e9;


void dfs(int st)
{
	s.push(st);
	if(st==p&&value[st]==b&&minn>s.size())
	{
		ans.clear();
		while(!s.empty())
		{
			ans.push_back(s.top());
			s.pop();
		}
		for ( int l : ans)
			s.push(l);
		reverse(ans.begin(),ans.end());
	}
    visited[st]=1;
    for(int v : K[st])
    {
    	if(visited[v]==0&&value[st]+vb[v]<=b)
    	{
    		value[v]=value[st]+vb[v];
    		dfs(v);
    		s.pop();
    		value[v]=value[v]-vb[v];
    		visited[v]=0;
   		}
	}
}

int main()
{
    freopen("CASTLE.INP", "r", stdin); 
    freopen("CASTLE.OUT", "w", stdout); 
    cin>>n>>m>>e>>p>>b;
    for(int i=1;i<=n;i++)
        cin>>vb[i];
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        K[u].push_back(v);
        K[v].push_back(u);
    }
    value[e]=vb[e];
    dfs(e);
    for(int x : ans)
    	cout<<x<<" ";
}
