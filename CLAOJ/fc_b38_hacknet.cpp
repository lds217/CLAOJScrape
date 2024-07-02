#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int N;
    cin>>N;
    int a[100000];
    for(int i=0;i<N;i++)
        cin>>a[i];
    sort(a,a+N);
    cout<<max((a[N-1]-a[0])*(a[N-2]-a[1]),(a[N-1]-a[1])*(a[N-2]-a[0]));
}
