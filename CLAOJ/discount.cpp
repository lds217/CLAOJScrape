#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,m;
    cin>>N>>m;;
    char str[200000];
    cin>>str;
    long long a[2000000]={0};
    
    for(int x=1;x<=N;x++)
        a[x]=a[x-1]+str[x-1]-('a'-1);
    
    int c,b;
    while(m--)
    {
        cin>>c>>b;
        long long k=a[b]-a[c-1];
        printf("%d",k);
        printf("\n");
    }
}
