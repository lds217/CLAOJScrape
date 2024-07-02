#include <bits/stdc++.h>
using namespace std;

#define int long long

int a[200001],bit[200001],n;

void update(int pos,int val)
{
    while(pos<=n)
    {
        bit[pos]+=val;
        pos+=pos&(-pos);
       
    }
}

int bit_search(int v)
{
	int sum = 0;
	int pos = 0;
	for(int i=18; i>=0; i--)
	{
		if(pos + (1 << i) < n && sum + bit[pos + (1 << i)] <= v)
		{
			sum += bit[pos + (1 << i)];
			pos += (1 << i);
		}
	}

	return pos + 1;
}
    

signed main()
{
    freopen("porder.inp", "r" , stdin);
    freopen("porder.out","w", stdout);
    int T;
    cin>>T;
    //   freopen("porder.inp", "r" , stdin);
//    freopen("porder.out","w", stdout);
   	while(T--)
    {
       
        cin>>n;
        for(int x=1;x<=n;x++)
        {
            cin>>a[x];
            update(x,1);
        }
       // for(int i=1;i<=n;i++)
          //  cout<<bit[i]<<' ';
        int res[200001];
        for(int x =n; x>=1;x--)
        {
            int j=bit_search(a[x]);
       //     cout<<j<<endl;
            res[x]=n-j+1;
           	update(j,-1);
        }
        for(int i=1;i<=n;i++)
            cout<<res[i]<<' ';
        cout<<endl;
    }
}
