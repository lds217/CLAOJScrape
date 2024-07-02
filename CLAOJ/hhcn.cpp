#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    double x,y,z;
    cin>>x>>y>>z;
    cout<<(long long)(   (sqrt(x*z/y)   +   x/(sqrt(x*z/y))   +   z/(sqrt(x*z/y)) )*4   )%1000000007;
}
