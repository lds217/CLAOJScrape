#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    long long n,m,maxneg=-1e9,minpos=1e9,dem=0,sum=0;
    cin>>n>>m;
    for(int x=0;x<n;x++)
        for(int y=0;y<m;y++)
        {
            long long a;
            cin>>a;
            sum+=abs(a);
            if(a<0)
            {
                maxneg=max(a,maxneg);
                dem++;
            }
            else
            {
                minpos=min(a,minpos);
            }
        }
    if(dem%2==0)
        cout<<sum;
    else
    {
        if(minpos+maxneg>=0)
            cout<<sum+maxneg+maxneg;
        else
            cout<<sum-minpos-minpos;
    }
     return 0;       
    cout<<sum;
}
