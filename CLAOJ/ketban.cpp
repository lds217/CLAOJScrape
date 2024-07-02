#include <bits/stdc++.h>
using namespace std;

vector<int> K[200001];
bool visited[200001];

void dfs(int u)
{
	visited[u]=1;
	for(int i: K[u])
		if(visited[i]==0)
			dfs(i);
}

int main()
{
	int N;
	cin>>N;
	int u,v;
	while(cin>>u>>v)
	{
		K[u].push_back(v);
		K[v].push_back(u);
	}
	dfs(1);
	for(int i=1;i<=N;i++)
		if(visited[i]==0)
		{
			cout<<0;
			return 0;
		}
	cout<<1;
	
}
