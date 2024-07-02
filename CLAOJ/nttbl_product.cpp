#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int c=0;
    while(n--)
    {
        long long u;
        cin>>u;
        if(u==0)
        {
            cout<<"0";
            return 0;
        }
        if(u<0)
            c++;
    }
    if(c%2==0)
        cout<<"+";
    else
        cout<<"-";
}
