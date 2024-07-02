#include <bits/stdc++.h>
#include <set>
using namespace std;

int n, m, s;
bool traverse[100000];
int value[1000000] = {0}; int visited[1000000] = {0};
vector<int> k[50000];
int cnt = 0;

// void dfs(int s)
// {
//     traverse[s] = 1;
//     for (auto x : k[s])
//     {
//         if (traverse[x]==0)
//         {
           
//             value[x]=value[s];
//             visited[x]=visited[s]+1;
//             dfs(x);
//             traverse [x]=0;
//         }
//         else
//             if(visited[x]==visited[s]+1&&visited[x]!=0)
//                 value[x]+=value[s];
//             else
//             {
//                 visited[x]=visited[s]+1;
//                 dfs(x);
//                 traverse [x]=0;
//             }
            
//     }
// }

int main()
{
    // dup[10001][10001]=1;
    int u, v;
    cin >> n >> m >> s;
    set< pair< int, int > > s1;
    int size=s1.size();
    for (int x = 0; x < m; x++)
    {
        cin >> u >> v;
        s1.insert(make_pair(u,v));
        if(s1.size()!=size)
        {
            k[u].push_back(v);
            size=s1.size();
        }
    }
    value[s]=visited[s]=1;
    //dfs(s);
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(auto v: k[u])
        if(visited[v]==0)
        {
            visited[v]=visited[u]+1;
            value[v]=value[u];
            q.push(v);
        }
        else
            if(visited[v]==visited[u]+1)
                value[v]+=value[u];

    }
    for(int x=1;x<=n;x++)
        if(value[x]>=2)
            cnt++;
    cout<<cnt;
}
