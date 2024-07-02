#include <iostream>
using namespace std;

int main()
{
    long long va,vb,vong,S,T;
    cin>>T;
    while(T--)
    {
    cin>>va>>vb>>vong>>S;
    cout<<(S*vong)/(va+vb)<<endl;
    }
}
