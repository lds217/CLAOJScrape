#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        long long N,X;
        cin>>N>>X;
        if((10-X)*(N-1)>0)
            cout<<(10-X)*(N-1)<<endl;
        else
            cout<<0<<endl;
    }
}
