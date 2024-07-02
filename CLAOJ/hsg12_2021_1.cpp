#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    unsigned long long n;
    cin>>n;
        cout<<5*30*((1+(n/5))*(n/5)/2)+(n/5+1)*(n%5)*30;
}
