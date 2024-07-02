#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long a[n+1];
    for(int x=0;x<n;x++)
        cin>>a[x];
    sort(a,a+n);
    cout<<max(a[0]*a[1],a[n-1]*a[n-2]);
}
