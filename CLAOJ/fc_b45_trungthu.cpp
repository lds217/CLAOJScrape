#include <iostream>
using namespace std;

int main()
{
    int n,k,minn=1e9;
    cin>>n>>k;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        sum+=a;
        if(a<minn) minn=a;
    }
    cout<<n+(k-sum)/minn;
}
