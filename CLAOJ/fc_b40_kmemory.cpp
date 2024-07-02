#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    long long N,K,a[500001];
    cin>>N>>K;
    for(int i=0;i<N;i++)
        cin>>a[i];
    unsigned long long res=0;
    for(int x=0;x<N;x++)
    {
        long long maxx=a[x],minn=a[x];
        for(int y=x-1;y>=0;y--)
        {
            maxx=max(maxx,a[y]);
            minn=min(minn,a[y]);
            if(maxx-minn<=K)
                res++;
            else
                break;
        }
    }
    cout<<res+N;
}
