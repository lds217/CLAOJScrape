#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector <int> k[5001];
bool visited[5001]={0};
int N,M,K,u,v,cnt=0;
int h[5001]={0};

void dfs(int i)
{
    cnt++;
   // cout<<"siu";
    visited[i]=1;
    for(auto j=k[i].begin();j<k[i].end();j++)
        if(visited[*j]==0&&h[*j]<=h[i])
            dfs(*j);
    
}

int main()
{
    
    cin>>N>>M>>K;
    for(int x=1;x<=N;x++)
        cin>>h[x];
    for(int x=1;x<=M;x++)
    {
        cin>>u>>v;
        k[u].push_back(v);
        k[v].push_back(u);
    }
    dfs(K);
    cout<<cnt;
}
