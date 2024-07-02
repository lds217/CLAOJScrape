#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> k[10000];
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        k[u].push_back(v);
        k[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j:k[i])
            if(j!=i)
                cout<<j<<' ';
        cout<<"0"<<endl;
    }
}
