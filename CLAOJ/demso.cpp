#include <iostream>
using namespace std;

int a[10000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt=1;
    while(cin>>a[cnt])
    {
        cnt++;
    }
    cout<<a[cnt/2];
}
