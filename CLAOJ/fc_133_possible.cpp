#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)

{
    int N;
    cin>>N;
    long long a[100000];
    long long sum=0,maxx=-1;
    for(int x=0;x<N;x++)
    {
        cin>>a[x],sum+=a[x],maxx=max(maxx,a[x]);
    }
    if(sum%2==1||maxx>sum-maxx)
    {
        cout<<"NO";
        return 0;
    }
   
    cout<<"YES";
}
