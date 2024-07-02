#include <bits/stdc++.h>
using namespace std;

long long N,M,a,arrmax[2000001],arrM[2000001],res=0;

int main()
{
    
    
    cin>>N;
    for(int x=1;x<=N;x++)
    {
        cin>>M;
        arrM[x]=M;
        for(int i=0;i<M;i++)
        {
            cin>>a;
            arrmax[x]=max(arrmax[x],a);
        }
    }
    for(int x=2;x<=N;x++)
    {
        long long k=abs(arrmax[x]-arrmax[x-1]);
        if(arrmax[x]>=arrmax[x-1])
            res+=k*arrM[x-1];
        else
            res+=k*arrM[x];
            arrM[x]+=arrM[x-1];
            arrmax[x]=max(arrmax[x],arrmax[x-1]);
    }
    cout<<res;
    
}
