#include <iostream>
using namespace std;

int main()
{
    int h,m,a,b;
    cin>>h>>m>>a>>b;
    cout<<(h+(b-a)+24)%24<<' '<<m;
}
