#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a,minn=1000000001,maxx=-1;
    for(int x=0;x<n;x++)
    {
        cin>>a;
        minn=min(minn,a);
        maxx=max(maxx,a);
    }
   cout<<maxx-minn;
}
