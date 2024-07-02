#include <iostream>
using namespace std;
 unsigned long long  a[1000001];
int main(int argc, char** argv)
{
    int N;
    cin>>N;
    for(int x=2; x<=1000000; x++)
    {
        for(int y=x+x;y<=1000000; y+=x)
            a[y]++;
    }
    unsigned long long sum=0;
    for(int x=1; x<=N; x++)
    {
         unsigned long long  u;
        cin>>u;
        if(u==1)
            sum++;
        else
        sum+= u*(a[u]+2);
    }
    cout<<sum;
}
