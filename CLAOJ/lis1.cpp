#include <iostream>
using namespace std;

int main()
{
    int n;
    unsigned long long a[1005],ss[1005];
    cin>>n;
    for(int i=0; i<n; i++) 
    {
        cin>>a[i];
        ss[i]=1;
    }
        int res=1;
        int cnt;
    for(int x=0; x<n-1; x++)
    {
        for(int i=x+1; i<n; i++)
            if(a[i]>a[x]&&ss[i]==ss[x])
                ss[i]++;
    }
    // for(int x=0; x<n; x++)
    //     cout<<ss[x]<<" ";
    int maxx=0;
     for(int x=0; x<n; x++)
        if(maxx<ss[x])
            maxx=ss[x];
    cout<<maxx;
}
