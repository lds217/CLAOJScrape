#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;cin>>n;
    long long a[200001];
    for(int i=0;i<n;i++)
        cin>>a[i];
       // long long ans=a[n-1];
       long long ans=0;
      //  cout<<ans;
      long long temp=1e18;
    for(int i=n-1;i>=0;i--)
    {
   //     if(a[i]<a[i-1]-1)
            temp=min(a[i],temp-1);
            ans+=max(temp,0LL);
            //cout<<min(a[i],a[i+1]-1)<<" ";
    }
    cout<<ans;
}
