#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    while(n--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        bool co=0;
        if(a+b==c)
            cout<<'+',co=1;
            if(a-b==c||b-a==c)
                cout<<'-',co=1;
                if(a*b==c)
                    cout<<'*',co=1;

                    if(c*b==a||c*a==b)
                        cout<<'/',co=1;
            if(co==0)
                        cout<<'?';
        cout<<endl;
    }
}
