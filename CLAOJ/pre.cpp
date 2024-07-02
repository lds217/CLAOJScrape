#include <bits/stdc++.h>
using namespace std;
char a;
int main()
{
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a=='V'||a=='I'||a=='P')  ans++;
    }
    cout<<ans/3;
}
