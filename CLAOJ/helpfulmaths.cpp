#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string str;
    cin>>str;
   	int pos=0,a[10000],cnta=0;
    for(int x=0;x<str.size();x++)
    {
        if(str[x]=='+')
        {
            a[cnta++]=stoll(str.substr(pos,x-pos));
        	pos=x+1;
        }
        if(x==str.size()-1)
            a[cnta++]=stoll(str.substr(pos,x-pos+1));
        
    }
    sort(a,a+cnta);
    for(int x=0;x<cnta;x++)
    {
        cout<<a[x];
        if(x!=cnta-1)
            cout<<'+';
    }
}
