#include <iostream>
#pragma gcc optimize
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    int a[1001][1001]={0},res=0;
    for(int j=0;j<N;j++)
    {
        for(int i=0;i<N;i++)
        {
            cin>>a[j][i];
            a[j][N]+=a[j][i];
            a[N][i]+=a[j][i];
        }
    }
    for(int j=0;j<N;j++)
        for(int i=0;i<N;i++)
            if(a[j][N]==a[N][i])
                res++;
    cout<<res;
}
