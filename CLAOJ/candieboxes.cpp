#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[1000001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=n;i>=n-m+1;i--) ans+=a[i];
    cout<<ans;
    return 0;
}
