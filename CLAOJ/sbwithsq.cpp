#include <bits/stdc++.h>
using namespace std;
int n, a[100001],b[100001],k,minn;

int main()
{
cin>>n;
minn=1000000001;
for (int i=1;i<=n;i++) 
    cin>>a[i];
for (int i=1;i<=n;i++) 
    cin>>b[i];


sort(a+1,a+1+n);

for (int i=1;i<=n;i++)
{
    k=lower_bound(a+1,a+1+n,-b[i])-a;
    if (k!=1) 
        minn=min(minn,abs(b[i]+a[k-1]));
    if (k!=n+1)
        minn=min(minn,abs(b[i]+a[k]));
}
    cout<<minn;
}
