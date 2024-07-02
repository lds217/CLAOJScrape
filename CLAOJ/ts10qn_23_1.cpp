#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("coor.inp","r",stdin);
    freopen("coor.out","w",stdout);
    int x=0, y=0;
    string s;
    cin>>s;
    for(char c:s)
    {
        if(c=='W')
            x--;
        if(c=='E')
            x++;
        if(c=='S')
            y--;
        if(c=='N')
            y++;
    }
    cout<<x<<' '<<y;
}
