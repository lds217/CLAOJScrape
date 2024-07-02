#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int sum=0;
    string str = to_string(n);
    for(int x=0;x<str.size();x++)
        sum+=str[x]-'0';
    while(sum%4!=0)
    {
        sum=0;
        n++;
        str=to_string(n);
        for(int x=0;x<str.size();x++)
        sum+=str[x]-'0';
    }
    cout<<n;
}
