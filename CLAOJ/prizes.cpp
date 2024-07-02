#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long long a[200001],f1[200001],f2[200001];

int main()
{
    int n,k;
    cin>>n>>k;
    
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    long long sum=0;
    for(int i=1;i<=k;i++)
        sum+=a[i];
    f1[k]=sum;
    for(int i=k+1;i<=n;i++)
    {
        sum-=a[i-k];
        sum+=a[i];
        f1[i]=max(sum,f1[i-1]);
    }
    sum=0;
     for(int i=n;i>=n-k+1;i--)
         sum+=a[i];
    f2[n-k+1]=sum;
    for(int i=n-k;i>=0;i--)
    {
        sum+=a[i];
        sum-=a[i+k];
        f2[i]=max(sum,f2[i+1]);
    }

    long long res=1e18;
    sum=0;
    for(int i=1;i<=k;i++)
        sum+=a[i];
    if(sum>=f1[0]&&sum>=f2[k+1])
        res=min(res,sum);
     for(int i=k+1;i<=n;i++)
    {
        res=min(max(f1[i-k],f2[i+1]),res);
    }
    cout<<res;
}
