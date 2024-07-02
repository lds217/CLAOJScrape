#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main()
{
    ifstream f;
    f.open("GCD.INP");
    int N,K;
    f>>N>>K;
    int a;
     int res[10000],cnt=0,check[10000]={0};
    for(int x=0;x<N;x++)
    {
        f>>a;
        if(a%K==0)
            res[cnt++]=a;
    }
    f.close();
    int final[10000],finalc=0;
    for(int x=0;x<cnt-1;x++)
    {
            for(int y=x+1;y<cnt;y++)
                if(__gcd(res[x],res[y])==K)
                {
                    if(check[x]==0)
                    {
                    final[finalc++]=res[x];
                        check[x]=1;
                    }
                    if(check[y]==0)
                    {
                    final[finalc++]=res[y];
                    check[y]=1;
                    }
                    res[x]=__gcd(res[x],res[y]);
                }
    }
    ofstream f1;
    f1.open("GCD.OUT");
    
    if(finalc==0)
    {
        f1<<-1;
        return 0;
    }
    f1<<finalc<<endl;
    for(int x=0;x<finalc;x++)
        f1<<final[x]<<" ";
        
    
}
