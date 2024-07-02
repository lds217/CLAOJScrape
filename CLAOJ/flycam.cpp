#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long l,r,d,k;
    int test;
    cin>>test;

    while(test--)
    {
        long long sum=0;
        cin>>l>>r>>d>>k;
        for(int i=l;i<=r;i+=d)
            sum+=abs(k-i);
        cout<<sum<<endl;
    }
}
