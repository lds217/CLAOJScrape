#include <iostream>
using namespace std;

int main()
{
    long long m;
    cin>>m;
    long long sum=0;
    if(m<5)
        sum+=12000*m;
    else
        sum+=10000*m;
    cout<<sum;
}
