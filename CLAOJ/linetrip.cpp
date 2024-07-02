#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;cin>>n;
    int a,minn=0,maxx=0;
    for(int i=0; i<n; i++)
    {
        cin>>a;
        minn=min(a,minn);
        maxx=max(a,maxx);
    }
    cout<<(maxx+abs(minn))*2;
}
