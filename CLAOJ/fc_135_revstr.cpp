#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int size=str.size();
    str=' '+str;
    int m;
    cin>>m;
    int a,prefix[200002]={0};
    while(m--)
    {
        cin>>a;
        prefix[a]++;
        prefix[size-a+1]=-1;
    }
    for(int x=1;x<=size/2;x++)
        prefix[x]+=prefix[x-1];
    for(int x=1;x<=size/2;x++)
    {
        if(prefix[x]%2!=0)
            swap(str[x],str[str.size()-x]);
    }
    str.erase(0,1);
    cout<<str;
}
