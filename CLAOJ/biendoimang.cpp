#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n,m,q,u,v,k,qq,pos[1000000]={0},neg[1000000]={0};
    cin>>n>>m>>q;
    long long a[1000000],cnt[1000000]={0};
    for(int x=1;x<=n;x++) 
        cin>>a[x];
    for(int x=1;x<=m;x++)
    {
        cin>>u>>v>>k;
        cnt[u]+=k;cnt[v+1]-=k;      
    }
    for(int x=2;x<=n;x++)
        cnt[x]+=cnt[x-1];
    for(int x=1;x<=n;x++)
    {
        if(cnt[x]+a[x]>=0)
            pos[cnt[x]+a[x]]++;
        else
            neg[abs(cnt[x]+a[x])]++;
    }
    for(int x=1;x<=q;x++)
    {
        cin>>qq;
        if(qq>=0)
            cout<<pos[qq]<<" ";
        else
            cout<<neg[abs(qq)]<<" ";
    }

}
