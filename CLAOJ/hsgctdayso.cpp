#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("DAYSO.INP", "r", stdin); 
    freopen("DAYSO.OUT", "w", stdout); 
	int N;
	cin>>N;
	int a[100001];
	for(int x=0;x<N;x++)
		cin>>a[x];
	int sum1=0,sum2=-1e9;
	int dem=0;
	for(int x=0;x<N;x++)
	{
		sum1+=a[x];
		sum2=max(sum2,sum1);
		if(sum1<0)
			sum1=0;
	}
	cout<<sum2;	
	  for(int x=0;x<N;x++)
    {
        int sum=a[x];
        for(int y=x+1;y<N;y++)
        {
            sum+=a[y];
            if(sum==sum2)
            	dem++;
        }
    }
    cout<<" "<<dem;
}
