#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,S;
    int dem=0;
    cin>>n>>S;
    for(int x=0;x<=n;x++)
        for(int y=0;y<=n;y++)
            if(S-x-y>=0&&S-x-y<=n)
                dem++;
    cout<<dem;
}
