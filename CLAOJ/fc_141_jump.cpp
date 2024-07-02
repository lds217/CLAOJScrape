#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    for(int x=1;x<=n/2;x++)
        cout<<x<<' '<<n-x+1<<" ";
    if(n%2!=0)
        cout<<n/2+1;
}
