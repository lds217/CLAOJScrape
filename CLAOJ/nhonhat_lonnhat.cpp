#include <iostream>
#include <string>

using namespace std;

int main()
{
    int M,S;
    cin>>M>>S;
    if(S>9*M)
    {
        cout<<"-1"<<" "<<"-1";
        return 0;
    }
    string maxx="";
    int cmaxx=S/9;
    for(int x=0;x<cmaxx;x++)
        maxx+='9';
        int K=S%9;
    maxx+=char(K+48);
    while(maxx.size()<M)
        maxx+='0';
    int cminn;
    string minn="";
    for(int x=M-1;x>=0;x--)
        minn+=maxx[x];
        if(minn[0]=='0')
        {
        int j=0;
            while(minn[j]=='0')
                j++;
        minn[0]='1';minn[j]--;
        }
    cout<<minn<<" "<<maxx;
}
