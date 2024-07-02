#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    int n;
    while(cin>>n)
    if(n!=-1)
    {
        long long sum=0;
        int a,b=0;
        while(n--)
        {
            int temp=b;
            cin>>a>>b;
            sum+=a*(b-temp);
        }
        cout<<sum<<" miles"<<endl;
    }
    else
        break;
}
