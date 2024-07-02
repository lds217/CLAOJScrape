#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("LADDER.INP","r",stdin);
	freopen("LADDER.OUT","w",stdout);
    int n,m,a[200001];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    a[n+1]=-1e9,a[0]=-1e9;
    int pos=1;
    int s1[200001];
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=a[i+1])
        {
        	s1[i]=pos;
            pos=i+1; 
        }
	}
    pos=n;
    int stair[200001];
    for(int i=n;i>=0;i--)
    {
        if(a[i-1]<a[i])
        {
        	stair[s1[i]]=pos;
        	pos=i-1;
        }
    }
    int range[200001];
    for(int i=1;i<=n;i++)
    {
        int tmp=i;
        while(stair[i]!=0&&tmp!=stair[i])
        {
            range[tmp]=stair[i];
            tmp++;
            
        }
	}
//	for(int i=1;i<=n;i++)
	//	cout<<range[i]<<' ';
//	cout<<endl;
	while(m--)
	{
		int u,v;
		cin>>u>>v;
		if(v<=range[u]||u==v)
			cout<<"Yes"<<endl;		
		else
			cout<<"No"<<endl;
	}
}
