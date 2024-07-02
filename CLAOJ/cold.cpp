#include <iostream>

using namespace std;


int main()
{
    int N;
    cin>>N;
    long long sum=0;
    while(N--)
    {
        int a;
        cin>>a;
        if(a<0)
            sum++;
    }
    cout<<sum;
}
