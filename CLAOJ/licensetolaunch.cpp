#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int N;
    cin>>N;
    int minn=1e9,a,pos=0;
    for(int x=0;x<N;x++)
    {
        cin>>a;
        if(a<minn)
        {
            minn=a;
            pos=x;
        }
    }
    cout<<pos;
}
