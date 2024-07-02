#include <bits/stdc++.h>
using namespace std;

vector <int> k[200001];
bool visited[200001]={0};
int M,N,u,v,cnt=0;

void dfs(int i)
{
    visited[i]=1;
    for(int j:k[i])
        if(visited[j]==0)
            dfs(j);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1;i<=M;i++)
    {
        cin >> u >> v;
        k[u].push_back(v);
        k[v].push_back(u);
    }
    for(int i=1;i<=N;i++)
        if(visited[i]==0)
        {
            cnt++;
            dfs(i);
        }
    cout << cnt;
}
