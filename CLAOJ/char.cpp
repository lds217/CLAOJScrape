#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    for(int x=0;x<str.size();x++)
        if(str[x]>='A'&&str[x]<='Z')
            str[x]+='a'-'A';
   	//cout<<str;
    int a['z'+1]={0};
    for(int x=0;x<str.size();x++)
        a[str[x]]++;
   	for(int x='a';x<='z';x++)
        if(a[x]>0)
        	cout<<(char)(x)<<" "<<a[x]<<endl;
}
