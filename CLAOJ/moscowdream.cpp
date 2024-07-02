#include <iostream>
using namespace std;

int main()
{
    int a,b,c,n;
    cin>>a>>b>>c>>n;
    if(a+b+c<n||a<=0||b<=0||c<=0||n<=2)
        cout<<"NO";
    else
        cout<<"YES";
}
