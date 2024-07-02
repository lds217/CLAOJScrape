#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    if(a==b||b==c||a==c)    while(1){cout<<"yes";}
    else
        cout<<a+b+c-max({a,b,c})-min({a,b,c});
}
