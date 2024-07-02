#include <iostream>
using namespace std;

long long X=0,Y=0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        char der;int value;
        cin>>der>>value;
        if(der=='W')
            X-=value;
        else
            if(der=='N')
                Y+=value;
            else
                if(der=='S')
                    Y-=value;
                else
                    X+=value;
    }
    cout<<X<<" "<<Y;
}
