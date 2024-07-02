#include <iostream>
using namespace std;

int ans[100001],cnt=0;

int main(int argc, char **argv)
{
    
    long long N,K;
    cin>>N>>K;
    while(N!=1)
    {
        if(N%K==0)
            N/=K,ans[cnt++]=1;
        else
            N++,ans[cnt++]=2;
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
        cout<<ans[i]<<" ";
}
