#include <iostream>
#include <vector>
using namespace std;
vector <int> k[2000000];
bool visited[2000000]={false};
int u,v,M,N,cnt=0;

void dfs(int i)
{
    visited[i]=1;
    for(auto j=k[i].begin();j<k[i].end();j++)
        if(visited[*j]==0)
            dfs(*j);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int x=1;x<=M;x++)
    {
        cin>>u>>v;
        k[u].push_back(v);
        k[v].push_back(u);
    }
    for(int x=1;x<=N;x++)
    {
        if(visited[x]==0)
        {
            cnt++;
            dfs(x);
        }
    }
    cout<<cnt-1;
}
