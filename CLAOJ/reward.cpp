#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
   // int z=0;
    cin>>n;
    long long a[10004]={0},check[100004]={0};
    check[1]=1;
    for(int x=1;x<=n;x++)cin>>a[x];
    long long res[100007]={0};
    res[1]=a[1];
    res[2]=res[1]+a[2];
    for(int x=3;x<=n+5;x++)
    {
        if(check[x-1]==1)
        {
            res[x]+=res[x-1]+a[x];
        }
        else
        {
            res[x]=max(res[x-3]+a[x-1]+a[x],res[x-2]+a[x]);
            if(res[x-1]>=res[x])
            {
                res[x]=res[x-1];
                check[x]=1;
            }
        }
    }
    long long maxx=0;
    for(int x=1;x<=n+3;x++)
       maxx=max(maxx,res[x]);
    cout<<maxx;
    return 0;
}
