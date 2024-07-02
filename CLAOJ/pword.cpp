#include <iostream>
#include <string>

using namespace std;

int main()
{
    int M,S;
    cin>>M>>S;
    if(S>9*M)
    {
        cout<<"-1";
        return 0;
    }
    string maxx="";
    int cmaxx=S/9;
    for(int x=0;x<cmaxx;x++)
        maxx+='9';
    if(maxx.size()<M)
    {
        int K=S%9;
    maxx+=char(K+48);
    }
    while(maxx.size()<M)
        maxx+='0';
    cout<<maxx;
}
