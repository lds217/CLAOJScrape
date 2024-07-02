#include <iostream>
#include <stdio.h>
using namespace std;

int eratos[1000001]={0};

void dperatos()
{
	eratos[0]=eratos[1]=1;
	for(int x=2;x*x<=1000001;x++)
	{
		if(eratos[x]==0)
		{
			for(int i=x*x;i<=1000001;i=i+x)
				if(eratos[i]==0)
					eratos[i]=1;
		}
	}
	int dem=0;
	for(int x=0;x<=1000001;x++)
	{
		if(eratos[x]==0)
			dem++;
		eratos[x]=dem;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	dperatos();
	int T;
	cin>>T;
	while(T--)
	{
		int L,R,sum=0;
		cin>>L>>R;
        sum=eratos[R]-eratos[L-1];
    printf("%d\n", sum);	

	}
}
