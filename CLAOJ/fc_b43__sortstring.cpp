#include <bits/stdc++.h>
using namespace std;




int main()
{
    string str;
    cin>>str;
    sort(str.begin(), str.end(),greater<char>());
    int i=str.size()-1;
    while(str[i]>='A'&&str[i]<='Z')
        i--;
    cout<<str.substr(i+1,str.size()-i)<<str.substr(0,i+1)<<endl;
}
