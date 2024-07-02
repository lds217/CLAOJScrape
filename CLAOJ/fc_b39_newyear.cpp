#include <iostream>
using namespace std;

int main()
{
    int n,cnt=0;
    cin>>n;
    int a[100000];
    for(int x=0;x<n;x++)
        cin>>a[x];
    int r=a[n-1];
    for(int x=n-2;x>=0;x--)
    {
        if(a[x]>r)
        {
            r=a[x];
            cnt++;
        }
    }
    cout<<cnt;
}
